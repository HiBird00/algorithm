import sys
sys.setrecursionlimit(100000)

N = int(input())
painting = []

for i in range(N) :
    painting.append(list(input()))

visited = [[False] * N for _ in range(N)]

nomal = 0
unique = 0

def section(y, x) :
    visited[y][x] = True
    for row, col in (1, 0), (0, 1), (-1, 0), (0, -1) :
        nextY, nextX = row+y, col+x
        if nextY >= 0 and nextY < N and nextX >= 0 and nextX < N :
            if not visited[nextY][nextX] and painting[nextY][nextX] == painting[y][x] :
                # 같은 색상이라면
                section(nextY, nextX)

for i in range(N) :
    for j in range(N) :
        if not visited[i][j] :
            section(i, j)
            nomal += 1

for i in range(N) :
    for j in range(N) :
        if painting[i][j] == 'G' :
            painting[i][j] = 'R'

visited = [[False] * N for _ in range(N)]

for i in range(N) :
    for j in range(N) :
        if not visited[i][j]:
            section(i, j)
            unique += 1

print(nomal, unique)