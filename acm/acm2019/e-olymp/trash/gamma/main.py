from sys import stdin
from math import gcd

def solve(a, b):
	return gcd(a, b) == 1

def solveWrapper(boo):
	if boo:
		return "YES"

	return "NO"

for line in stdin:
	a, b = [int(i) for i in line.split()]
	if a < b:
		a, b = b, a
	print(solveWrapper(solve(a, b)))
