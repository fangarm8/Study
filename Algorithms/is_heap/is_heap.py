def is_heap(arr, n):
    flag = 1
    for i in range(n, 0, -1):
        if arr[i] < arr[i // 2]:
            flag = 0
    return flag

with open('input.txt', 'r') as file:
    n = int(file.readline())
    line = list(map(int, file.readline().split()))
    money = [line[0]]
    for i in range(n):
        money.append(line[i])
    is_it = is_heap(money, n)
    with open('output.txt', 'w') as out:
        if is_it:
            out.write('Yes')
        else:
            out.write('No')