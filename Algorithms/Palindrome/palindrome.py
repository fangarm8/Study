def build_matrix(s):
    res = []
    for i in range(s):
        tmp = [1 for _ in range(i+1)]
        res.append(tmp)
    return res

def palindrome(s, F):
    n = len(s)
    if n==1:
        return F[0][0]
    for i in range(0, n-1):
        F[i+1][i] = 2 if s[i]==s[i+1] else 1
    for j in range(2, n-1):
        for i in range(0, n-j):
            F[i+j][i] = F[i+j-1][i+1] + 2 if s[i]==s[i+j] else max(F[i+j][i+1], F[i+j-1][i])
    F[n-1][0] = F[n-2][1] + 2 if s[0]==s[n-1] else max(F[n-1][1], F[n-2][0])
    return F[n-1][0]

def recover_palindrome(s, F):
    n = len(s)
    i = 0
    j = n-1
    str_pal = ''
    while i >= 0 and j >= i:
        if(s[i]==s[j]):
            str_pal = f'{str_pal}{s[i]}'
            i+=1
            j-=1
        else:
            if max(F[j][i+1], F[j-1][i]) == F[j-1][i]:
                j-=1
            else:
                i+=1
    if(F[n-1][0]%2==1):
        for i in range(len(str_pal)-2, -1, -1):
            str_pal = f'{str_pal}{str_pal[i]}'
    else:
        for i in range(len(str_pal)-1, -1, -1):
            str_pal = f'{str_pal}{str_pal[i]}'

    return str_pal

with open('input.txt', 'r') as file:
    s = file.readline()
F = build_matrix(len(s))

lp = palindrome(s, F)
str_pal = recover_palindrome(s, F)

with open('output.txt', 'w') as file:
    file.write(str(lp))
    file.write('\n'+str_pal)