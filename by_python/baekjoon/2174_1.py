A, B = map(int, input().split())
N, M = map(int, input().split())
land = [[-1]*A for _ in range(B)]
robot_pos = []

for i in range(N) :
    # 로봇 위치
    x, y, dir = input().split()
    robot_pos.append((B-int(y), int(x)-1))
    dirInt = -1
    if dir == 'E' :
        dirInt = 0
    elif dir == 'S' :
        dirInt = 1
    elif dir == 'W' :
        dirInt = 2
    elif dir == 'N' :
        dirInt = 3
    land[B-int(y)][int(x)-1] = dirInt


answer = 'OK'

for i in range(M) :
    # 명령
    robot, command, num = input().split()
    num = int(num)
    robot = int(robot)
    y, x = robot_pos[robot-1]
    dir = land[y][x]
    if command == 'F' :
        # 앞으로
        crash = False
        if dir == 0 :
            # 동
            for j in range(1, num+1) :
                nextX = x+j
                if nextX >= A :
                    # 벽 충돌
                    answer = "Robot {0} crashes into the wall".format(robot)
                    crash = True
                    break
                elif land[y][nextX] != -1 :
                    answer = "Robot {0} crashes into robot {1}".format(robot, robot_pos.index((y, nextX))+1)
                    crash = True
                    break
            if crash : 
                break
            land[y][x+num] = 0
            land[y][x] = -1
            robot_pos[robot-1] = (y, x+num)
        elif dir == 2 :
            # 서
            for j in range(1, num+1) :
                nextX = x-j
                if nextX < 0 :
                    # 벽 충돌
                    answer = "Robot {0} crashes into the wall".format(robot)
                    crash = True
                    break
                elif land[y][nextX] != -1 :
                    answer = "Robot {0} crashes into robot {1}".format(robot, robot_pos.index((y, nextX))+1)
                    crash = True
                    break
            if crash : 
                break
            land[y][x-num] = 2
            land[y][x] = -1
            robot_pos[robot-1] = (y, x-num)
        elif dir == 1 :
            # 남
            for j in range(1, num+1) :
                nextY = y+j
                if nextY >= B :
                    # 벽 충돌
                    answer = "Robot {0} crashes into the wall".format(robot)
                    crash = True
                    break
                elif land[nextY][x] != -1 :
                    answer = "Robot {0} crashes into robot {1}".format(robot, robot_pos.index((nextY, x))+1)
                    crash = True
                    break
            if crash : 
                break
            land[y+num][x] = 1
            land[y][x] = -1
            robot_pos[robot-1] = (y+num, x)
        elif dir == 3 :
            # 북
            for j in range(1, num+1) :
                nextY = y-j
                if nextY < 0 :
                    # 벽 충돌
                    answer = "Robot {0} crashes into the wall".format(robot)
                    crash = True
                    break
                elif land[nextY][x] != -1 :
                    answer = "Robot {0} crashes into robot {1}".format(robot, robot_pos.index((nextY, x))+1)
                    crash = True
                    break
            if crash : 
                break
            land[y-num][x] = 3
            land[y][x] = -1
            robot_pos[robot-1] = (y-num, x)
    elif command == 'R' :
        # 오른쪽 90도 회전
        newDir = (dir + num) % 4
    elif command == 'L' :
        newDir = dir
        for cnt in range(num%4) :
            newDir -= 1
            if newDir == -1 :
                newDir = 3
    
print(answer)
