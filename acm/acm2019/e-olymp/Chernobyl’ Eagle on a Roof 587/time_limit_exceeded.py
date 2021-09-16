from array import array

N = 1000

res = [array('l', [0] * (N + 1)) for i in range(N + 1)]
for i in range(N + 1):
	res[i][1] = i
	res[1][i] = 1

for i in range(2, N + 1):
	# print(i)
	bestPoint = (i + 1) // 2

	for j in range(2, N + 1):
		point = bestPoint
		val = 1 + max(res[point - 1][j - 1], res[i - point][j])
		
		point -= 1

		endPoint = res[i - 1][j]
		while point >= endPoint:
			newVal = 1 + max(res[point - 1][j - 1], res[i - point][j])
			
			if val >= newVal:
				val = newVal
			else:
				break

			point -= 1

		res[i][j] = val

while True:
	a, b = [int(i) for i in input().split()]

	if a == b == 0:
		break

	print(res[b][a])
