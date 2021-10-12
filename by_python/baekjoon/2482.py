N = int(input())
K = int(input())
MOD = 1000000003
color = [[-1]*(K+1) for _ in range(N+1)]

def selectColor(n, k) :
    if k == 1 :
        return n
    elif k < 1 :
        return 0
    if n//2 < k :
        return 0
    
    ret = color[n][k]
    if ret != -1 :
        return ret

    color[n][k] = (selectColor(n-2, k-1) + selectColor(n-1, k)) % MOD
    return color[n][k]

print(selectColor(N, K))