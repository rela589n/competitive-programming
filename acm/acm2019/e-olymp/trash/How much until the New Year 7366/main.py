
n = int(input())

n, s = divmod(n, 60)
n, m = divmod(n, 60)
n, h = divmod(n, 24)
n, d = divmod(n, 356)

print("%d %d %d %d" % (d, h, m, s))
