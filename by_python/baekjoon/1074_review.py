N, r, c = map(int, input().split())
answer = 0
while N > 0 :
    part = -1
    div = 2**(N-1)

    if r >= div :
        if c >= div :
            part = 3
            r -= div
            c -= div
        else :
            part = 2
            r -= div
    else :
        if c >= div :
            part = 1
            c -= div
        else :
            part = 0

    answer += part*(4**(N-1))
    N -= 1

print(answer)