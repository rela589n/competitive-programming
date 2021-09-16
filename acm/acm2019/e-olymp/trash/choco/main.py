

r, c = [int(i) for i in input().split()]
matrix = [[int(j) for j in input().split()] for i in range(r)]

def checkRows():
    for i in range(r - 1):
    	for j in range(c):
    		if matrix[i][j] != matrix[i + 1][j]:
    			continue
    		break
    	else:
    		return True

    return False

def checkCols():
    for j in range(c - 1):
    	for i in range(r):
    		if matrix[i][j] != matrix[i][j + 1]:
    			continue
    		break
    	else:
    		return True

    return False
        

def boolWrapper(boo):
    return "Yes" if boo else "No"

print(boolWrapper(checkRows() or checkCols()))
# input()

"""
3 4
3 4 5 5
3 4 6 6
1 1 2 2

2 3
1 1 2
3 3 2

1 4
1 1 2 2

1 2
1 1


"""
