import sys

def tsp(start, visited, total):
    visited[start] = True
    # 모두 다 방문
    if all(visited):
        return total
    
    res = []
    for next in range(n):
        if not visited[next]:
            res.append(tsp(next, visited, total + arr[start][next]))
            visited[next]=False
    
    return min(res)



c = int(sys.stdin.readline())
result = []

for _ in range(c):
    n = int(sys.stdin.readline())
    arr = []
    local = []

    for _ in range(n):
        temp = list(map(float, sys.stdin.readline().split()))
        arr.append(temp)
    
    for start in range(n):
        visited = [0]*n
        local.append(tsp(start, visited, 0))
    result.append(min(local))
    
for res in result:
    print("%.10f" % res)

