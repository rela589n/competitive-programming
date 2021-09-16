def inf():
	return float("inf")

n = int(input())

vals = [int(i) for i in input().split()]

vals.append(inf())
vals.append(inf())

result = [inf()] * (n + 2)
result[0] = 0

for i in range(n - 1):
	result[i + 1] = min(result[i + 1], result[i] + abs(vals[i] - vals[i + 1]))
	result[i + 2] = min(result[i + 2], result[i] + 3 * abs(vals[i] - vals[i + 2]))

print(result[n - 1])