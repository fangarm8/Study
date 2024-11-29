def read():
    res = []
    with open('input.txt', 'r') as file:
        n = int(file.readline().strip())
        for _ in range(n):
            a, b = map(int, file.readline().split())
            res.append((a,b))
    return res, n

def build_matrix(s):
    res = []
    for i in range(s):
        tmp = [0 for _ in range(i+1)]
        res.append(tmp)
    return res

def sol():
    input, s = read()
    F = build_matrix(s)
    for j in range(1, s):
        for i in range(j-1, -1, -1):
            F[j][i] = float('Inf')
            for k in range (i, j):
                tmp = F[k][i] + F[j][k+1] + input[i][0]*input[k][1]*input[j][1]
                if F[j][i] > tmp:
                    F[j][i] = tmp
    return F[s-1][0]

res = sol()
with open('output.txt', 'w') as file:
    file.write(str(res))