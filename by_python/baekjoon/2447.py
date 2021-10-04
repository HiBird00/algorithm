def star(x, y, N) :
    if(N == 1) :
        stars[y][x] = '*'
        return
    num = N // 3
    for i in range(3) :
        for j in range(3) :
            if(i == 1 and j == 1) :
                continue
            star(x+j*num, y+i*num, num)
            
    
n = int(input())
stars = [[' ' for i in range(n)] for _ in range(n)]
star(0, 0, n)

for i in range(n) : 
    print(''.join(stars[i]))
