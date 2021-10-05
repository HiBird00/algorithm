import sys

N, M = map(int, input().split())
blueray = list(map(int, sys.stdin.readline().split()))

min_width = max(blueray)
max_width = sum(blueray)
answer = max_width

while min_width <= max_width :
    mid_width = (min_width + max_width) // 2
    
    cnt = 0
    width = 0
    for i in blueray :
        if(width+i > mid_width) :
            # 블루레이 하나 채움
            cnt += 1
            width = 0
        width += i

    if width : 
        cnt += 1

    if cnt > M :
        # 블루레이가 더 많이 나오면 용량 늘려야함
        min_width = mid_width+1
    else : 
        answer = mid_width
        max_width = mid_width-1

print(answer)