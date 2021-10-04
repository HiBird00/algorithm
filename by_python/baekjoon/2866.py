R, C = map(int, input().split())
s = []

for row in range(R) :
    s.append(input())

start = 0
end = R-1

while start <= end :
    mid = (start + end) // 2

    midList = s[mid:]
    setList = []
    check = False
    for j in range(C) :
        temp = ''
        for i in range(len(midList)) :
            temp += midList[i][j]
        if temp in setList :
            # 중복이 있다면
            check = True
            break
        else :
            setList.append(temp)   
                
    if(check) :
        end = mid-1
    else :
        start = mid+1

print(start-1)