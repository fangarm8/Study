mod = 1000000007
def step(a, n):
    res = 1
    while(n > 0):
        if n%2==1:
            res = (res%mod*a%mod)%mod
        a = (a%mod*a%mod)%mod
        n>>=1
    return res

def C(n, k):
    if k==0:
        return 1
    if k>n:
        return 0
    div1 = 1
    for i in range(0, k):
        div1 = (div1%mod*(n-i)%mod)%mod
    div2 = 1
    for i in range(1, k+1):
        div2 = (div2%mod*i%mod)%mod
    return int(div1%mod * step(div2, mod-2))%mod

n, k = map(int, input().split())
if k > n-k:
    print(C(n,n-k))
else:
    print(C(n,k))