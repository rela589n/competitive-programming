n, d = [int(i) for i in input().split()]
digits = [i == '1' for i in input()]

results = [float('inf')] * n
results[0] = 0

for i in range(n):
	for j in range(i + 1, min(i + d + 1, n)):
		if not digits[j]:
			continue
		
		results[j] = min(results[j], results[i] + 1)

print(int(results[n - 1]) if results[n - 1] != float('inf') else -1)

# input()