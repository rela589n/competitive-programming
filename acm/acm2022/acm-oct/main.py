from itertools import groupby

n = int(input())
s = input()
l = len(s)
ar = [i for i in s]
un = [x[0] for x in groupby(ar)]
lw = len(un)

print((n - 1) * (l +1) + 1+ (n - 1) * l + lw)
