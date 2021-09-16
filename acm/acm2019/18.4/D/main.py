n = int(input())
g = [i == '1' for i in input().split()]
s = [i == '1' for i in input().split()]

gSum = sum(g)
sSum = sum(s)

probable = [i for i in range(len(s)) if not s[i] and g[i]]

if (len(probable) == 0):
	print(-1)
else:
	result = [1] * n
	while gSum <= sSum:
		for i in probable:
			gSum += 1
			result[i] += 1

	print(max(result))
# input()