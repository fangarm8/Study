def alibaba(array, ans):
    for j in range(1, len(ans)):
        for i in range(len(ans) - j):
            ans[i][i+j] = min(ans[i][i+j-1] + array[i+j][0] - array[i+j-1][0], 
                            ans[i+j-1][i] + array[i+j][0] - array[i][0])
            
            if ans[i][i+j] > array[i+j][1]:
                ans[i][i+j] = float('inf')
            
            ans[i+j][i] = min(ans[i+j][i+1] + array[i+1][0] - array[i][0], 
                              ans[i+1][i+j] + array[i+j][0] - array[i][0])
            
            if ans[i+j][i] > array[i][1]:
                ans[i+j][i] = float('inf')
    return min(ans[0][len(ans)-1], ans[len(ans)-1][0])

with open('input.txt', 'r') as file:
    n = int(file.readline())
    money = []
    for _ in range(n):
        tmp = list(map(int, file.readline().split()))
        money.append(tmp)
    ans = [[0 for _ in range(n)] for _ in range(n)]

total = alibaba(money, ans)
with open('output.txt', 'w') as file:
    if total == float('inf'):
        file.write('No solution')
    else:
        file.write(str(total))

    