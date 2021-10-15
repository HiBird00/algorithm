import sys
input = sys.stdin.readline

N, M = map(int, input().split())
numbers = [[0]*(N+1)]
cmd = []
n_sum = [[0]*(N+1) for _ in range(N+1)]

for _ in range(N) :
    numbers.append(list(map(int, input().split())))
    numbers[-1].insert(0, 0)

for _ in range(M) :
    cmd.append(list(map(int, input().split())))

# 모두 채우기
for i in range(1, N+1) :
    for j in range(1, N+1) :
        n_sum[i][j] = n_sum[i-1][j] + n_sum[i][j-1] + numbers[i][j] - n_sum[i-1][j-1]


for n in range(M) :
    x1, y1, x2, y2 = cmd[n]
    print(n_sum[x2][y2] - n_sum[x1-1][y2] - n_sum[x2][y1-1] + n_sum[x1-1][y1-1])
