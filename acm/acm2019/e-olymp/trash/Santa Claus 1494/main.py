n, m, k = [int(i) for i in input().split()]

result = [False] * n

for i in input().split():
	result[int(i) - 1] = True

for i in input().split():
	result[int(i) - 1] = True

print(n - m - k)
print(*[i + 1 for i in range(n) if not result[i]], ' ')

