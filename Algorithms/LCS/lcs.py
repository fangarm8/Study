def sol(n, a1, a2):
    F = [[0 for _ in range(n+1)] for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(1, n+1):
            if a1[i-1] == a2[j-1]:
                F[j][i] = F[j-1][i-1] + 1
            else:
                F[j][i] = max(F[j-1][i], F[j][i-1])
    return F

# def longestCommonSubsequence(a1: str, a2: str) -> int:
#     n = len(a1)
#     m = len(a2)
#     F = [[0 for _ in range(m+1)] for _ in range(n+1)]
#     for i in range(1, m+1):
#         for j in range(1, n+1):
#             if a1[j-1] == a2[i-1]:
#                 F[j][i] = F[j-1][i-1] + 1
#             else:
#                 F[j][i] = max(F[j-1][i], F[j][i-1])
#     return F[n][m]

def recover_lcs(F, a1, a2):
    ind1 = []
    ind2 = []
    n = len(a1)
    i = n
    j = n
    while i > 0 and j > 0:
        if a1[i-1] == a2[j-1]:
            ind1.append(i-1)
            ind2.append(j-1)
            i-=1
            j-=1
        else:
            if F[j][i] == F[j-1][i]:
                j-=1
            else:
                i-=1
    return ind1, ind2


n = int(input())
a1 = list(map(int, input().split()))
a2 = list(map(int, input().split()))
F = sol(n, a1, a2)
ind1, ind2 = recover_lcs(F, a1, a2)
print(F[n][n])
print(' '.join(map(str, ind1[::-1])))
print(' '.join(map(str, ind2[::-1])))
# a1 = input()
# a2 = input()
# Fstr = longestCommonSubsequence(a1, a2)
# print(Fstr)