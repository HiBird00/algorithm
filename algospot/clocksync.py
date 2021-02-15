import sys

def clocksync(clock, switch):
    ret = 98765432
    # 전부 12시인 경우
    if switch == len(swit):
        if check(clock):
            return 0
        else:
            return ret

    for cnt in range(4):
        ret = min(ret, cnt + clocksync(clock, 1 + switch))
        push(clock, switch) # 원상복귀 됨 (마지막에 총 4번 누름)
    
    return ret

def push(clock, switch):
    for num in swit[switch]:
        clock[num] += 3
        if clock[num] == 15:
            clock[num] = 3


def check(clock):
    for i in range(len(clock)):
        if clock[i] != 12:
            return False
    return True

swit = [
    [0,1,2],
    [3,7,9,11],
    [4,10,14,15],
    [0,4,5,6,7],
    [6,7,8,10,12],
    [0,2,14,15],
    [3,14,15],
    [4,5,7,14,15],
    [1,2,3,4,5],
    [3,4,5,9,13]
]

c = int(sys.stdin.readline())
result = []
for _ in range(c):
    clock = list(map(int, sys.stdin.readline().split()))

    result.append(clocksync(clock, 0))

for res in result:
    print(res)

      

    