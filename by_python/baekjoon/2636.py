row, col = map(int, input().split()) # 세로, 가로
tray = []

for i in range(row) :
    tray.append(list(map(int, input().split()))); 

def dfs(queue, prev, time) :
    cheese = []
    while queue : 
        y, x = queue.pop(0)
        for dy, dx in (0, 1), (-1, 0), (0, -1), (1, 0) :
            nextY, nextX = y+dy, x+dx
            if nextY >= 0 and nextY < row and nextX >= 0 and nextX < col :
                if tray[nextY][nextX] == 0 :
                    queue.append((nextY, nextX))
                    tray[nextY][nextX] = -1
                elif tray[nextY][nextX] == 1 :
                    cheese.append((nextY, nextX))
                    tray[nextY][nextX] = -1

    if not cheese :
       # 다 녹음
       print(time)
       print(prev)
       return
    
    # 치즈를 0으로 바꾸기
    for (i, j) in cheese :
        tray[i][j] = 0
    
    dfs(cheese, len(cheese), time+1)

dfs([(0,0)], 0, 0)