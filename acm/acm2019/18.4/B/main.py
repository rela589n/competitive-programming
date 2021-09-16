n, v = [int(i) for i in input().split()]

spent = min(n - 1, v)
stock = spent

for city in range(2, n + 1):
	stock -= 1

	if (stock < n - city):
		stock += 1
		spent += city

print(spent)
# input()
