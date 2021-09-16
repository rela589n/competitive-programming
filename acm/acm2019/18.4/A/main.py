n, k = [int(i) for i in input().split()]

def dec(num):
	if num % 10 == 0:
		num /= 10
	else:
		num -= 1

	return num

for i in range(k):
	n = dec(n)

print(int(n))

# input()