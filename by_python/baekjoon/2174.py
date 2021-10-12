E, S, W, N = 1,2,3,4
dirX = [0, 1, 0, -1, 0]
dirY = [0, 0, 1, 0, -1]

A, B = map(int, input().split())
N, M = map(int, input().split())
land = [[-1]*A for _ in range(B)]
robot = [[0, 0]]
answer = 'OK'

for i in range(N) :
    x, y, dir = input().split()
    x, y = int(x), int(y)
    if dir == 'W' : dir = W
    elif dir == 'S' : dir = S
    elif dir == 'E' : dir = E
    elif dir == 'N' : dir = N
    robot.append([x-1, B-y, dir])
    land[B-y][x-1] = i+1

for i in range(M) :
    r_idx, cmd, num = input().split()
    r_idx, num = int(r_idx), int(num)
    
    if cmd == 'F' :
        # 직진
        crash = False
        nextX, nextY = robot[r_idx][0], robot[r_idx][1]
        for _ in range(num) :
            nextX += dirX[robot[r_idx][2]]
            nextY += dirY[robot[r_idx][2]]
            if nextX < 0 or nextX >= A or nextY < 0 or nextY >= B :
                answer = 'Robot {} crashes into the wall'.format(r_idx)
                crash = True
                break
            elif land[nextY][nextX] != -1 :
                answer = 'Robot {0} crashes into robot {1}'.format(r_idx, land[nextY][nextX])
                crash = True
                break

        if crash : 
            break
        x, y = robot[r_idx][0], robot[r_idx][1]
        land[nextY][nextX] = r_idx
        land[y][x] = -1
        robot[r_idx][0], robot[r_idx][1] = nextX, nextY
    else : 
        cnt = num%4
        if cmd == 'R' :
            for _ in range(cnt) :
                if robot[r_idx][2] == 4 :
                    robot[r_idx][2] = 1
                else : 
                    robot[r_idx][2] += 1
        elif cmd == 'L' :
            for _ in range(cnt) :
                if robot[r_idx][2] == 1 :
                    robot[r_idx][2] = 4
                else : 
                    robot[r_idx][2] -= 1
            

print(answer)

