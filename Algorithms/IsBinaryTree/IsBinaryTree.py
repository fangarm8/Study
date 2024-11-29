import numpy as np

def borders(arr, lines):
    for i in range(2, int(lines[0][0])+1):
        child = int(lines[i][0])
        parent = int(lines[i][1])
        char = lines[i][2]
        v = np.array([int(lines[i][0]), int(lines[i][1])], dtype = int)
        if char == 'L':
            if arr[parent][0] > v[0] or v[0] >= arr[parent][1]:
                return False
            arr[i][0] = arr[parent][0]
            arr[i][1] = child
            arr[i][2] = arr[parent][1]
        else:
            if arr[parent][1] > v[0] or v[0] >= arr[parent][2]:
                return False
            arr[i][0] = arr[parent][1]
            arr[i][1] = v[0]
            arr[i][2] = arr[parent][2]
    return True

lines = []
with open('bst.in', 'r') as file:
    for line in file:
        lines.append(tuple(line.split()))

arr = np.zeros((int(lines[0][0]) + 1, 3), dtype = int) #[[0, 0, 0] for i in range(int(lines[0][0]) + 1)]

arr[1][0] = -2147483649
arr[1][1] = int(lines[1][0])
arr[1][2] = 2147483648

isbst = borders(arr, lines)

with open('bst.out', 'w') as file:
    if isbst:
        file.write('YES')
    else:
        file.write('NO')