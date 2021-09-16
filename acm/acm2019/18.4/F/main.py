
n = int(input())

def solve(num):
	lst = [0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341, 390, 439]

	if num < 14:
		return lst[num]

	return 390 + 49 * (num - 13)


print(solve(n))

