R, C = map(int, input().split())
tray = []

for i in range(R) :
    tray.append(list(map(int, input().split())))

def meltCheese(queue, time, piece) :
    cheese = []
    while queue :
        y, x = queue.pop()
        for row, col in (0, 1), (1, 0), (0, -1), (-1, 0) :
            nextY, nextX = y+row, x+col
            if nextY >= 0 and nextY < R and nextX >= 0 and nextX < C :
                if tray[nextY][nextX] == 0 :
                    tray[nextY][nextX] = -1
                    queue.append((nextY, nextX))
                elif tray[nextY][nextX] == 1 :
                    tray[nextY][nextX] = -1
                    cheese.append((nextY, nextX))
    
    if cheese :
        for cy, cx in cheese :
            tray[cy][cx] = 0
        meltCheese(cheese, time+1, len(cheese))
    else :
        print(time)
        print(piece)
        return
    
meltCheese([(0, 0)], 0, 0)
