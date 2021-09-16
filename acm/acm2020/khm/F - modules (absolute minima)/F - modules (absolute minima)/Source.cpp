/**
The main idea is that optimal x will be the median of sorted A elements.
We could notice this if draw couple of charts in photomath.
For instance, [1,2,3,4] - optimal x is 2 or 3. Here on we'll stick to the leftmost.
If array has odd number of elements, say [1,2,3], x is middle 2.

Therefore trivial solution would look like this:

<?php
$q = (int)(readline());

$foo = static fn() => 0;

$totalB = 0;
$as = [];
while ($q--) {
	$input = array_map('intval', explode(' ', trim(readline())));
	if ($input[0] === 1) {
		[$_, $a, $b] = $input;
		$totalB += $b;
		$as[]= $a;
		$foo = static fn($x) => $foo($x) + abs($x - $a);
	}
	else {
		sort($as);
		$x = $as[intdiv(count($as) - 1, 2)];
		$res = $foo($x) + $totalB;

		echo "$x $res" . PHP_EOL;
	}
}

As you see in the code above, we actually have $foo function which will is actually updated. You know, dynamic nature of php.
Once query is necessary, array $as is sorted so that we definitely know where X is located.
Onward, we get function value as $foo($x) + $totalB and print X and Foo(X).

Code like this works well, but it doesnt fit in time limits.

## Solution
Given that array A is sorted, minimum foo(x) will be in point a3.
foo(x) = |x - a1| + |x - a2| + |x - a3| + |x - a4| + |x - a5|

All values before a3 are less than a3.
Therefore, we can optimize sum operation if we know left_sum = sum[0..m], and right_sum = sum[m+1..n-1], where m - median index.

foo(x) = x * (m + 1) - left_sum + right_sum - x * (n - 1 - m)

To accomplish this, we will keep 2 sorted arrays, first - left sorted part (includes median), second - right sorted part.
C++ has priority_queue for the rescue.

Queues for 1 2 3 7 8 9 will look like:
left:  1 2 3
right: 9 8 7

Everything else is shown in code and is implementation details...
*/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

priority_queue<int> q_left;
ll left_sum = 0;

priority_queue<int, vector<int>, greater<int>> q_right;
ll right_sum = 0;

ll t, B = 0;

inline void push_left(ll a) {
	q_left.push(a);
	left_sum += a;
}

inline void push_right(ll a) {
	q_right.push(a);
	right_sum += a;
}

inline ll pop_left() {
	ll ret = q_left.top();
	q_left.pop();
	left_sum -= ret;
	return ret;
}

inline ll pop_right() {
	ll ret = q_right.top();
	q_right.pop();
	right_sum -= ret;
	return ret;
}

inline ll foo(ll x) {
	return  q_left.size() * x - left_sum 
		+ right_sum - q_right.size() * x
		+ B;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		ll t;
		cin >> t;

		if (t == 1) {
			ll a, b;
			cin >> a >> b;

			B += b;

			if (q_left.size() == 0) {
				push_left(a);
				continue;
			}

			// make sure first contains n/2 elements, second the rest
			if (q_left.size() > q_right.size()) {
				push_right(a);
			}
			else {
				push_left(a);
			}

			// swap elements if two queues together are not sequential 
			if (q_left.top() > q_right.top()) {
				// 1 3 5 7
				// 9 8 6 
				// will become
				// 1 3 5 6
				// 9 8 7

				push_left(pop_right());
				push_right(pop_left());
			}

		} 
		else {
			ll x = q_left.top();

			cout << x << " " << foo(x) << endl;
		}
	}

	return 0;
}

/*

4
1 -1000000000 1000000000
1 -1000000000 1000000000
1 -1000000000 1000000000
2

4
1 4 2
2
1 1 -8
2

*/