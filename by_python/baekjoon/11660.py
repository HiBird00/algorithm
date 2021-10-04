import sys

N, M = map(int, sys.stdin.readline().split())
n_list = []

for i in range(N) :
    n_list.append(list(map(int, sys.stdin.readline().split())))

# 누적합
s_list = [[0]*(N+1) for _ in range(N+1)]

for x in range(1, N+1) :
    for y in range(1, N+1) :
        s_list[x][y] = s_list[x-1][y] + s_list[x][y-1] + n_list[x-1][y-1] - s_list[x-1][y-1]

while M : 
    M -= 1

    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    
    print(s_list[x2][y2] - s_list[x1-1][y2] - s_list[x2][y1-1] + s_list[x1-1][y1-1])
    
