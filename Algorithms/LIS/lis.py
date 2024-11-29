def low(array, x):
    l = 0
    r = len(array)
    
    while l < r:
        i = (l + r) // 2
        if x <= array[i]:
            r = i
        else:
            l = i + 1
    return l

def longest(arr):
    LIS = []
    for x in arr:
        i = low(LIS, x)
        if i == len(LIS):
            LIS.append(x)
        elif LIS[i] != x:
            LIS[i] = x
    return LIS

with open('input.txt', 'r') as file:
    size = int(file.readline().strip())
    arr = list(map(int, file.readline().split()))

result = longest(arr)

with open('output.txt', 'w') as output_file:
    output_file.write(str(len(result)))
    print(len(result))