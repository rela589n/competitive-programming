#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <list>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include <functional>

/*
 * C++ implementation of timsort
 *
 * ported from Python's and OpenJDK's:
 * - http://svn.python.org/projects/python/trunk/Objects/listobject.c
 * - http://cr.openjdk.java.net/~martin/webrevs/openjdk7/timsort/raw_files/new/src/share/classes/java/util/TimSort.java
 *
 * Copyright (c) 2011 Fuji, Goro (gfx) <gfuji@cpan.org>.
 * Copyright (c) 2019 Morwenn.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef GFX_TIMSORT_HPP
#define GFX_TIMSORT_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <vector>

 // Semantic versioning macros

#define GFX_TIMSORT_VERSION_MAJOR 2
#define GFX_TIMSORT_VERSION_MINOR 0
#define GFX_TIMSORT_VERSION_PATCH 0

// Diagnostic selection macros

#ifdef GFX_TIMSORT_ENABLE_ASSERT
#   include <cassert>
#   define GFX_TIMSORT_ASSERT(expr) assert(expr)
#else
#   define GFX_TIMSORT_ASSERT(expr) ((void)0)
#endif

#ifdef GFX_TIMSORT_ENABLE_LOG
#   include <iostream>
#   define GFX_TIMSORT_LOG(expr) (std::clog << "# " << __func__ << ": " << expr << std::endl)
#else
#   define GFX_TIMSORT_LOG(expr) ((void)0)
#endif


namespace gfx {

	// ---------------------------------------
	// Implementation details
	// ---------------------------------------

	namespace detail {

		// Equivalent to C++20 std::identity
		struct identity {
			template <typename T>
			constexpr T&& operator()(T&& value) const noexcept
			{
				return std::forward<T>(value);
			}
		};

		// Merge a predicate and a projection function
		template <typename Compare, typename Projection>
		struct projection_compare {
			projection_compare(Compare comp, Projection proj) : compare(comp), projection(proj) {
			}

			template <typename T, typename U>
			bool operator()(T&& lhs, U&& rhs) {
#ifdef __cpp_lib_invoke
				return static_cast<bool>(std::invoke(compare,
					std::invoke(projection, std::forward<T>(lhs)),
					std::invoke(projection, std::forward<U>(rhs))
				));
#else
				return static_cast<bool>(compare(
					projection(std::forward<T>(lhs)),
					projection(std::forward<U>(rhs))
				));
#endif
			}

			Compare compare;
			Projection projection;
		};

		template <typename Iterator> struct run {
			typedef typename std::iterator_traits<Iterator>::difference_type diff_t;

			Iterator base;
			diff_t len;

			run(Iterator b, diff_t l) : base(b), len(l) {
			}
		};

		template <typename RandomAccessIterator, typename Compare> class TimSort {
			typedef RandomAccessIterator iter_t;
			typedef typename std::iterator_traits<iter_t>::value_type value_t;
			typedef typename std::iterator_traits<iter_t>::reference ref_t;
			typedef typename std::iterator_traits<iter_t>::difference_type diff_t;

			static const int MIN_MERGE = 32;
			static const int MIN_GALLOP = 7;

			int minGallop_; // default to MIN_GALLOP

			std::vector<value_t> tmp_; // temp storage for merges
			typedef typename std::vector<value_t>::iterator tmp_iter_t;

			std::vector<run<RandomAccessIterator> > pending_;

			static void binarySort(iter_t const lo, iter_t const hi, iter_t start, Compare compare) {
				GFX_TIMSORT_ASSERT(lo <= start);
				GFX_TIMSORT_ASSERT(start <= hi);
				if (start == lo) {
					++start;
				}
				for (; start < hi; ++start) {
					GFX_TIMSORT_ASSERT(lo <= start);
					value_t pivot = std::move(*start);

					iter_t const pos = std::upper_bound(lo, start, pivot, compare);
					for (iter_t p = start; p > pos; --p) {
						*p = std::move(*(p - 1));
					}
					*pos = std::move(pivot);
				}
			}

			static diff_t countRunAndMakeAscending(iter_t const lo, iter_t const hi, Compare compare) {
				GFX_TIMSORT_ASSERT(lo < hi);

				iter_t runHi = lo + 1;
				if (runHi == hi) {
					return 1;
				}

				if (compare(*runHi, *lo)) { // decreasing
					do {
						++runHi;
					} while (runHi < hi && compare(*runHi, *(runHi - 1)));
					std::reverse(lo, runHi);
				}
				else { // non-decreasing
					do {
						++runHi;
					} while (runHi < hi && !compare(*runHi, *(runHi - 1)));
				}

				return runHi - lo;
			}

			static diff_t minRunLength(diff_t n) {
				GFX_TIMSORT_ASSERT(n >= 0);

				diff_t r = 0;
				while (n >= MIN_MERGE) {
					r |= (n & 1);
					n >>= 1;
				}
				return n + r;
			}

			TimSort() : minGallop_(MIN_GALLOP) {
			}

			// Silence GCC -Winline warning
			~TimSort() {}

			void pushRun(iter_t const runBase, diff_t const runLen) {
				pending_.push_back(run<iter_t>(runBase, runLen));
			}

			void mergeCollapse(Compare compare) {
				while (pending_.size() > 1) {
					diff_t n = pending_.size() - 2;

					if ((n > 0 && pending_[n - 1].len <= pending_[n].len + pending_[n + 1].len) ||
						(n > 1 && pending_[n - 2].len <= pending_[n - 1].len + pending_[n].len)) {
						if (pending_[n - 1].len < pending_[n + 1].len) {
							--n;
						}
						mergeAt(n, compare);
					}
					else if (pending_[n].len <= pending_[n + 1].len) {
						mergeAt(n, compare);
					}
					else {
						break;
					}
				}
			}

			void mergeForceCollapse(Compare compare) {
				while (pending_.size() > 1) {
					diff_t n = pending_.size() - 2;

					if (n > 0 && pending_[n - 1].len < pending_[n + 1].len) {
						--n;
					}
					mergeAt(n, compare);
				}
			}

			void mergeAt(diff_t const i, Compare compare) {
				diff_t const stackSize = pending_.size();
				GFX_TIMSORT_ASSERT(stackSize >= 2);
				GFX_TIMSORT_ASSERT(i >= 0);
				GFX_TIMSORT_ASSERT(i == stackSize - 2 || i == stackSize - 3);

				iter_t base1 = pending_[i].base;
				diff_t len1 = pending_[i].len;
				iter_t base2 = pending_[i + 1].base;
				diff_t len2 = pending_[i + 1].len;

				GFX_TIMSORT_ASSERT(len1 > 0);
				GFX_TIMSORT_ASSERT(len2 > 0);
				GFX_TIMSORT_ASSERT(base1 + len1 == base2);

				pending_[i].len = len1 + len2;

				if (i == stackSize - 3) {
					pending_[i + 1] = pending_[i + 2];
				}

				pending_.pop_back();

				diff_t const k = gallopRight(*base2, base1, len1, 0, compare);
				GFX_TIMSORT_ASSERT(k >= 0);

				base1 += k;
				len1 -= k;

				if (len1 == 0) {
					return;
				}

				len2 = gallopLeft(*(base1 + (len1 - 1)), base2, len2, len2 - 1, compare);
				GFX_TIMSORT_ASSERT(len2 >= 0);
				if (len2 == 0) {
					return;
				}

				if (len1 <= len2) {
					mergeLo(base1, len1, base2, len2, compare);
				}
				else {
					mergeHi(base1, len1, base2, len2, compare);
				}
			}

			template <typename Iter>
			diff_t gallopLeft(ref_t key, Iter const base, diff_t const len, diff_t const hint, Compare compare) {
				GFX_TIMSORT_ASSERT(len > 0);
				GFX_TIMSORT_ASSERT(hint >= 0);
				GFX_TIMSORT_ASSERT(hint < len);

				diff_t lastOfs = 0;
				diff_t ofs = 1;

				if (compare(*(base + hint), key)) {
					diff_t const maxOfs = len - hint;
					while (ofs < maxOfs && compare(*(base + (hint + ofs)), key)) {
						lastOfs = ofs;
						ofs = (ofs << 1) + 1;

						if (ofs <= 0) { // int overflow
							ofs = maxOfs;
						}
					}
					if (ofs > maxOfs) {
						ofs = maxOfs;
					}

					lastOfs += hint;
					ofs += hint;
				}
				else {
					diff_t const maxOfs = hint + 1;
					while (ofs < maxOfs && !compare(*(base + (hint - ofs)), key)) {
						lastOfs = ofs;
						ofs = (ofs << 1) + 1;

						if (ofs <= 0) {
							ofs = maxOfs;
						}
					}
					if (ofs > maxOfs) {
						ofs = maxOfs;
					}

					diff_t const tmp = lastOfs;
					lastOfs = hint - ofs;
					ofs = hint - tmp;
				}
				GFX_TIMSORT_ASSERT(-1 <= lastOfs);
				GFX_TIMSORT_ASSERT(lastOfs < ofs);
				GFX_TIMSORT_ASSERT(ofs <= len);

				return std::lower_bound(base + (lastOfs + 1), base + ofs, key, compare) - base;
			}

			template <typename Iter>
			diff_t gallopRight(ref_t key, Iter const base, diff_t const len, diff_t const hint, Compare compare) {
				GFX_TIMSORT_ASSERT(len > 0);
				GFX_TIMSORT_ASSERT(hint >= 0);
				GFX_TIMSORT_ASSERT(hint < len);

				diff_t ofs = 1;
				diff_t lastOfs = 0;

				if (compare(key, *(base + hint))) {
					diff_t const maxOfs = hint + 1;
					while (ofs < maxOfs && compare(key, *(base + (hint - ofs)))) {
						lastOfs = ofs;
						ofs = (ofs << 1) + 1;

						if (ofs <= 0) {
							ofs = maxOfs;
						}
					}
					if (ofs > maxOfs) {
						ofs = maxOfs;
					}

					diff_t const tmp = lastOfs;
					lastOfs = hint - ofs;
					ofs = hint - tmp;
				}
				else {
					diff_t const maxOfs = len - hint;
					while (ofs < maxOfs && !compare(key, *(base + (hint + ofs)))) {
						lastOfs = ofs;
						ofs = (ofs << 1) + 1;

						if (ofs <= 0) { // int overflow
							ofs = maxOfs;
						}
					}
					if (ofs > maxOfs) {
						ofs = maxOfs;
					}

					lastOfs += hint;
					ofs += hint;
				}
				GFX_TIMSORT_ASSERT(-1 <= lastOfs);
				GFX_TIMSORT_ASSERT(lastOfs < ofs);
				GFX_TIMSORT_ASSERT(ofs <= len);

				return std::upper_bound(base + (lastOfs + 1), base + ofs, key, compare) - base;
			}

			static void rotateLeft(iter_t first, iter_t last)
			{
				value_t tmp = std::move(*first);
				iter_t last_1 = std::move(first + 1, last, first);
				*last_1 = std::move(tmp);
			}

			static void rotateRight(iter_t first, iter_t last)
			{
				iter_t last_1 = last - 1;
				value_t tmp = std::move(*last_1);
				std::move_backward(first, last_1, last);
				*first = std::move(tmp);
			}


			void mergeLo(iter_t const base1, diff_t len1, iter_t const base2, diff_t len2, Compare compare) {
				GFX_TIMSORT_ASSERT(len1 > 0);
				GFX_TIMSORT_ASSERT(len2 > 0);
				GFX_TIMSORT_ASSERT(base1 + len1 == base2);

				if (len1 == 1) {
					return rotateLeft(base1, base2 + len2);
				}
				if (len2 == 1) {
					return rotateRight(base1, base2 + len2);
				}

				copy_to_tmp(base1, len1);

				tmp_iter_t cursor1 = tmp_.begin();
				iter_t cursor2 = base2;
				iter_t dest = base1;

				*dest = std::move(*cursor2);
				++cursor2;
				++dest;
				--len2;

				int minGallop(minGallop_);

				// outer:
				while (true) {
					diff_t count1 = 0;
					diff_t count2 = 0;

					do {
						GFX_TIMSORT_ASSERT(len1 > 1);
						GFX_TIMSORT_ASSERT(len2 > 0);

						if (compare(*cursor2, *cursor1)) {
							*dest = std::move(*cursor2);
							++cursor2;
							++dest;
							++count2;
							count1 = 0;
							if (--len2 == 0) {
								goto epilogue;
							}
						}
						else {
							*dest = std::move(*cursor1);
							++cursor1;
							++dest;
							++count1;
							count2 = 0;
							if (--len1 == 1) {
								goto epilogue;
							}
						}
					} while ((count1 | count2) < minGallop);

					do {
						GFX_TIMSORT_ASSERT(len1 > 1);
						GFX_TIMSORT_ASSERT(len2 > 0);

						count1 = gallopRight(*cursor2, cursor1, len1, 0, compare);
						if (count1 != 0) {
							std::move_backward(cursor1, cursor1 + count1, dest + count1);
							dest += count1;
							cursor1 += count1;
							len1 -= count1;

							if (len1 <= 1) {
								goto epilogue;
							}
						}
						*dest = std::move(*cursor2);
						++cursor2;
						++dest;
						if (--len2 == 0) {
							goto epilogue;
						}

						count2 = gallopLeft(*cursor1, cursor2, len2, 0, compare);
						if (count2 != 0) {
							std::move(cursor2, cursor2 + count2, dest);
							dest += count2;
							cursor2 += count2;
							len2 -= count2;
							if (len2 == 0) {
								goto epilogue;
							}
						}
						*dest = std::move(*cursor1);
						++cursor1;
						++dest;
						if (--len1 == 1) {
							goto epilogue;
						}

						--minGallop;
					} while ((count1 >= MIN_GALLOP) | (count2 >= MIN_GALLOP));

					if (minGallop < 0) {
						minGallop = 0;
					}
					minGallop += 2;
				} // end of "outer" loop

			epilogue: // merge what is left from either cursor1 or cursor2

				minGallop_ = (std::min)(minGallop, 1);

				if (len1 == 1) {
					GFX_TIMSORT_ASSERT(len2 > 0);
					std::move(cursor2, cursor2 + len2, dest);
					*(dest + len2) = std::move(*cursor1);
				}
				else {
					GFX_TIMSORT_ASSERT(len1 != 0 && "Comparison function violates its general contract");
					GFX_TIMSORT_ASSERT(len2 == 0);
					GFX_TIMSORT_ASSERT(len1 > 1);
					std::move(cursor1, cursor1 + len1, dest);
				}
			}

			void mergeHi(iter_t const base1, diff_t len1, iter_t const base2, diff_t len2, Compare compare) {
				GFX_TIMSORT_ASSERT(len1 > 0);
				GFX_TIMSORT_ASSERT(len2 > 0);
				GFX_TIMSORT_ASSERT(base1 + len1 == base2);

				if (len1 == 1) {
					return rotateLeft(base1, base2 + len2);
				}
				if (len2 == 1) {
					return rotateRight(base1, base2 + len2);
				}

				copy_to_tmp(base2, len2);

				iter_t cursor1 = base1 + len1;
				tmp_iter_t cursor2 = tmp_.begin() + (len2 - 1);
				iter_t dest = base2 + (len2 - 1);

				*dest = std::move(*(--cursor1));
				--dest;
				--len1;

				int minGallop(minGallop_);

				// outer:
				while (true) {
					diff_t count1 = 0;
					diff_t count2 = 0;

					// The next loop is a hot path of the algorithm, so we decrement
					// eagerly the cursor so that it always points directly to the value
					// to compare, but we have to implement some trickier logic to make
					// sure that it points to the next value again by the end of said loop
					--cursor1;

					do {
						GFX_TIMSORT_ASSERT(len1 > 0);
						GFX_TIMSORT_ASSERT(len2 > 1);

						if (compare(*cursor2, *cursor1)) {
							*dest = std::move(*cursor1);
							--dest;
							++count1;
							count2 = 0;
							if (--len1 == 0) {
								goto epilogue;
							}
							--cursor1;
						}
						else {
							*dest = std::move(*cursor2);
							--cursor2;
							--dest;
							++count2;
							count1 = 0;
							if (--len2 == 1) {
								++cursor1; // See comment before the loop
								goto epilogue;
							}
						}
					} while ((count1 | count2) < minGallop);
					++cursor1; // See comment before the loop

					do {
						GFX_TIMSORT_ASSERT(len1 > 0);
						GFX_TIMSORT_ASSERT(len2 > 1);

						count1 = len1 - gallopRight(*cursor2, base1, len1, len1 - 1, compare);
						if (count1 != 0) {
							dest -= count1;
							cursor1 -= count1;
							len1 -= count1;
							std::move_backward(cursor1, cursor1 + count1, dest + (1 + count1));

							if (len1 == 0) {
								goto epilogue;
							}
						}
						*dest = std::move(*cursor2);
						--cursor2;
						--dest;
						if (--len2 == 1) {
							goto epilogue;
						}

						count2 = len2 - gallopLeft(*(cursor1 - 1), tmp_.begin(), len2, len2 - 1, compare);
						if (count2 != 0) {
							dest -= count2;
							cursor2 -= count2;
							len2 -= count2;
							std::move(cursor2 + 1, cursor2 + (1 + count2), dest + 1);
							if (len2 <= 1) {
								goto epilogue;
							}
						}
						*dest = std::move(*(--cursor1));
						--dest;
						if (--len1 == 0) {
							goto epilogue;
						}

						--minGallop;
					} while ((count1 >= MIN_GALLOP) | (count2 >= MIN_GALLOP));

					if (minGallop < 0) {
						minGallop = 0;
					}
					minGallop += 2;
				} // end of "outer" loop

			epilogue: // merge what is left from either cursor1 or cursor2

				minGallop_ = (std::min)(minGallop, 1);

				if (len2 == 1) {
					GFX_TIMSORT_ASSERT(len1 > 0);
					dest -= len1;
					std::move_backward(cursor1 - len1, cursor1, dest + (1 + len1));
					*dest = std::move(*cursor2);
				}
				else {
					GFX_TIMSORT_ASSERT(len2 != 0 && "Comparison function violates its general contract");
					GFX_TIMSORT_ASSERT(len1 == 0);
					GFX_TIMSORT_ASSERT(len2 > 1);
					std::move(tmp_.begin(), tmp_.begin() + len2, dest - (len2 - 1));
				}
			}

			void copy_to_tmp(iter_t const begin, diff_t len) {
				tmp_.assign(std::make_move_iterator(begin),
					std::make_move_iterator(begin + len));
			}

		public:

			static void sort(iter_t const lo, iter_t const hi, Compare compare) {
				GFX_TIMSORT_ASSERT(lo <= hi);

				diff_t nRemaining = (hi - lo);
				if (nRemaining < 2) {
					return; // nothing to do
				}

				if (nRemaining < MIN_MERGE) {
					diff_t const initRunLen = countRunAndMakeAscending(lo, hi, compare);
					GFX_TIMSORT_LOG("initRunLen: " << initRunLen);
					binarySort(lo, hi, lo + initRunLen, compare);
					return;
				}

				TimSort ts;
				diff_t const minRun = minRunLength(nRemaining);
				iter_t cur = lo;
				do {
					diff_t runLen = countRunAndMakeAscending(cur, hi, compare);

					if (runLen < minRun) {
						diff_t const force = (std::min)(nRemaining, minRun);
						binarySort(cur, cur + force, cur + runLen, compare);
						runLen = force;
					}

					ts.pushRun(cur, runLen);
					ts.mergeCollapse(compare);

					cur += runLen;
					nRemaining -= runLen;
				} while (nRemaining != 0);

				GFX_TIMSORT_ASSERT(cur == hi);
				ts.mergeForceCollapse(compare);
				GFX_TIMSORT_ASSERT(ts.pending_.size() == 1);

				GFX_TIMSORT_LOG("size: " << (hi - lo) << " tmp_.size(): " << ts.tmp_.size()
					<< " pending_.size(): " << ts.pending_.size());
			}
		};

	} // namespace detail


	// ---------------------------------------
	// Public interface implementation
	// ---------------------------------------

	/**
	 * Stably sorts a range with a comparison function and a projection function.
	 */
	template <typename RandomAccessIterator, typename Compare, typename Projection>
	void timsort(RandomAccessIterator const first, RandomAccessIterator const last,
		Compare compare, Projection projection) {
		typedef detail::projection_compare<Compare, Projection> compare_t;
		compare_t comp(std::move(compare), std::move(projection));
		detail::TimSort<RandomAccessIterator, compare_t>::sort(first, last, std::move(comp));
	}

	/**
	 * Same as std::stable_sort(first, last, compare).
	 */
	template <typename RandomAccessIterator, typename Compare>
	void timsort(RandomAccessIterator const first, RandomAccessIterator const last, Compare compare) {
		gfx::timsort(first, last, compare, detail::identity());
	}

	/**
	 * Same as std::stable_sort(first, last).
	 */
	template <typename RandomAccessIterator>
	void timsort(RandomAccessIterator const first, RandomAccessIterator const last) {
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
		gfx::timsort(first, last, std::less<value_type>(), detail::identity());
	}

	/**
	 * Stably sorts a range with a comparison function and a projection function.
	 */
	template <typename RandomAccessRange, typename Compare, typename Projection>
	void timsort(RandomAccessRange& range, Compare compare, Projection projection) {
		gfx::timsort(std::begin(range), std::end(range), compare, projection);
	}

	/**
	 * Same as std::stable_sort(std::begin(range), std::end(range), compare).
	 */
	template <typename RandomAccessRange, typename Compare>
	void timsort(RandomAccessRange& range, Compare compare) {
		gfx::timsort(std::begin(range), std::end(range), compare);
	}

	/**
	 * Same as std::stable_sort(std::begin(range), std::end(range)).
	 */
	template <typename RandomAccessRange>
	void timsort(RandomAccessRange& range) {
		gfx::timsort(std::begin(range), std::end(range));
	}

} // namespace gfx

#undef GFX_TIMSORT_ENABLE_ASSERT
#undef GFX_TIMSORT_ASSERT
#undef GFX_TIMSORT_ENABLE_LOG
#undef GFX_TIMSORT_LOG

#endif // GFX_TIMSORT_HPP



#define Int long long
#define ll Int
#define dbl long double

bool _flag_forelse = false;
#define For(loop) for(Int loop)

#define __COMMA__ ,
#define ForParam(iter, start, size)  For(iter = start __COMMA__ __for_size = size; iter < __for_size; ++iter)
#define ForI(n) ForParam(i, 0, n)
#define ForJ(m) ForParam(j, 0, m)
#define ForK(l) ForParam(k, 0, l)

#define forelse(loop) _flag_forelse = false; for (loop, _flag_forelse=true)
#define empty bool __flag_forelse_copy = _flag_forelse; _flag_forelse = true;  if(!__flag_forelse_copy)
#define Forelse(loop) forelse(Int loop)

#define readI(var) Int var; cin >> var;
#define readF(var) double var; cin >> var;
#define readD(var) dbl var; cin >> var;

#define unless(condition)if(!condition)

#define $ auto
#define mkarr(size, type) new Int[size];
#define _matrix(rows, cols, type) vector<vector<type>>(rows, vector<type>(cols))
#define matrix(rows, cols) _matrix(rows, cols, Int)

#define _Vector(size, type) vector<type> (size)
#define Vector(size) _Vector(size, ll)

#define _read_vector(vec, start, end) ForParam(i, start, end) cin >> vec[i];
#define read_vector(vec) _read_vector(vec, 0, vec.size())
#define print_vector(vec, delim) ForI(vec.size()) { cout << vec[i] << delim; }
#define multiStr(a) #a

#define read_matrix(vec) ForI(vec.size()) { ForJ(vec[i].size()) { cin >> vec[i][j]; } }

#define use(space) using namespace space


use(std);

template <class Tkey, class Tval>
class HashMap {
private:
	class HashEntry;
	HashEntry** table;
	int TABLE_SIZE;

	class HashEntry {
	private:
		Tkey key;
		Tval value;
	public:
		HashEntry(Tkey key, Tval value) {
			this->key = key;
			this->value = value;
		}

		Tkey getKey() {
			return key;
		}

		Tval& getValue() {
			return value;
		}
	};

	void init() {
		this->keys = list<Tkey>();
		table = new HashEntry * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; ++i)
			table[i] = nullptr;
	}

	unsigned int (*hashFunc)(Tkey);

	static unsigned int hashDefault(Tkey key) {
		return key;
	}

	list<Tkey> keys;

public:
	HashMap(int tableSize = 128, unsigned int(*setHashFunction)(Tkey) = hashDefault) {
		this->TABLE_SIZE = tableSize;
		this->hashFunc = setHashFunction;
		init();
	}

	Tval& operator [] (Tkey key) {
		int hash = (hashFunc(key) % TABLE_SIZE);

		while (table[hash] != nullptr && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;

		if (table[hash] == nullptr) {
			table[hash] = new HashEntry(key, Tval());
			this->keys.push_back(key);
		}
		return table[hash]->getValue();
	}

	list<Tkey> getKeys() {
		return this->keys;
	}

	bool isset(Tkey key) {
		int hash = (hashFunc(key) % TABLE_SIZE);
		while (table[hash] != nullptr && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;

		return table[hash] != nullptr;
	}

	void put(Tkey key, Tval value) {
		int hash = (hashFunc(key) % TABLE_SIZE);
		while (table[hash] != nullptr && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;

		if (table[hash] != nullptr) {
			delete table[hash];
		}
		else {
			this->keys.push_back(key);
		}

		table[hash] = new HashEntry(key, value);
	}

	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; ++i)
			if (table[i] != nullptr)
				delete table[i];
		delete[] table;
	}
};

int reverseLLLastSize;

ll reverseLL(ll in) {
	reverseLLLastSize = 0;

	ll out = 0;
	while (in)
	{
		out *= 10;
		out += in % 10;
		in /= 10;

		++reverseLLLastSize;
	}

	return out;
}
// a < b
bool compareIntsAsString(ll a, ll b) {
	if (a == b) return true;
	if (a < 0 && b >= 0) return true;
	if (b < 0 && a >= 0) return false;

	if (a < 0) {
		a = -a;
	}

	if (b < 0) {
		b = -b;
	}

	a = reverseLL(a);
	int lenA = reverseLLLastSize;

	b = reverseLL(b);
	int lenB = reverseLLLastSize;

	if (a == b) {
		return lenA < lenB;
	}

	while (a && b) {
		int pa = a % 10;
		int pb = b % 10;

		if (pa < pb) {
			return true;
		}
		if (pa > pb) {
			return false;
		}
		
		a /= 10;
		b /= 10;
	}

	return a < b;
}


bool _envTest_ = false;
void runProduction() {
	cin.tie(nullptr);

	size_t n;
	cin >> n;

	vector<ll> vec(n);
	for (size_t i = 0; i < n; ++i) {
		ll val = 0ll;

		//cin >> val;
		scanf("%lld", &val);
		vec[i] = val;
	}

	stable_sort(vec.begin(), vec.end());
	//sort(vec.begin(), vec.end());

	HashMap<ll, pair<int, int> > indexesBeforeAfter = HashMap<ll, pair<int, int> >(n * 4);

	for (size_t i = 0; i < n; ++i) {
		indexesBeforeAfter[vec[i]] = make_pair(i, -1);
	}

	gfx::timsort(vec.begin(), vec.end(), compareIntsAsString);

	for (size_t i = 0; i < n; ++i) {
		indexesBeforeAfter[vec[i]].second = i;
	}
	
	ll maxShift = 0;
	ll number = vec[0];

	for (size_t i = 0; i < n; ++i) {
		pair<int, int> indexes = indexesBeforeAfter[vec[i]];

		ll val = abs(indexes.first - indexes.second);

		if (maxShift < val || (maxShift == val && vec[i] < number)) {
			maxShift = val;
			number = vec[i];
		}
	}

	cout << number << endl;
	//system("pause");
	 
}

vector< pair<const char*, const char*> > tests =
{
	make_pair(multiStr(
		as
	), "25")
};


void runTests() {
	streambuf* orig = std::cin.rdbuf();
	{
		ForI(tests.size()) {
			istringstream myinput(tests[i].first);
			cin.rdbuf(myinput.rdbuf());

			cout << tests[i].first << endl;
			runProduction();
			cout << " => " << tests[i].second << endl;
		}
	}
	cin.rdbuf(orig);
}

int main() {
	if (_envTest_) {
		runTests();
		system("pause");
		return 0;
	}

	runProduction();
	return 0;
}
