
def numsSum(num):
	return sum(int(d) for d in str(num))

n = int(input())

c = 0
for i in range(10, 100):
	if (numsSum(i) == numsSum(i * n)):
		c += 1
print(c)

# input()
