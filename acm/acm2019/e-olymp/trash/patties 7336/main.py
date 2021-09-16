
a, b, n = [int(i) for i in input().split()]
result = n * a * 100 + (n * b)
print(int(result / 100), int(result % 100))
