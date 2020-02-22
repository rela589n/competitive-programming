n = int(input())
string = input()
strings = list(filter(None, input().split(' ')))

for i in strings:
	if i != string:
		print("NO")
		break
else:
	print("YES")
