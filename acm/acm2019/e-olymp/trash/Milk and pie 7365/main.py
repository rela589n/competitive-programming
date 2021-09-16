from math import ceil

n = int(input())

count = 0
for i in input().split():
	w = float(i)
	if w < 30:
		count += 1

print(ceil(count * 2 / 9), count)

# input()