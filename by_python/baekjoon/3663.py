N = int(input())

while N :
    N -= 1
    name = input()
    answer = 0
    cnt = len(name)-1
    for i in range(len(name)) :
        answer += min(91-ord(name[i]), ord(name[i])-65)
        
        next = i+1
        while next < len(name) and name[next] == 'A':
            next += 1
        right = i*2 + len(name)-next
        left = i + (len(name)-next) * 2
        pos = min(right, left)
        cnt = min(cnt, pos)
    answer += cnt
    print(answer)