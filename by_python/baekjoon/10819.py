N = int(input())
arr = list(map(int, input().split()))
visited = [False]*N
answer = 0
select = [-1]*N

def getSum(array) :
    sum = 0
    for i in range(len(array)-1) :
        sum += abs(array[i]-array[i+1])
    return sum

def solve(cnt) :
    global answer
    if cnt == N :
        answer = max(answer, getSum(select))
        return
    
    for i in range(N) :
        if not visited[i] :
            visited[i] = True
            select[cnt] = arr[i]
            solve(cnt+1)
            visited[i] = False

solve(0)
print(answer)
