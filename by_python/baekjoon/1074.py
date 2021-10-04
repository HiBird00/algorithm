N, r, c = map(int, input().split())

def visitZ(row, col, n, cnt) :
    if n == 0 :
        print(cnt)
        return

    posR = True # true : 위, false 아래
    posC = True # true : 왼, false 오른쪽

    if row >= 2**(n-1) :
        posR = False
    if col >= 2**(n-1) : 
        posC = False

    idx = 0
    if posR and posC : 
        #위, 왼
        idx = 0
    elif posR and not posC : 
        #위, 오
        idx = 1
        col = col % (2**(n-1))
    elif not posR and posC :
        idx = 2
        row = row % (2**(n-1))
    else : 
        idx = 3
        row = row % (2**(n-1))
        col = col % (2**(n-1))
    
    visitZ(row, col, n-1, cnt+(4**(n-1)*idx))

visitZ(r, c, N, 0)
