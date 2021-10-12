import bisect
import sys

N, H = map(int, sys.stdin.readline().split())
s, j = [], []
answer = []

for i in range(N) :
    h = int(sys.stdin.readline())
    if i % 2 :
        # 증류석
        j.append(H-h+1)
    else :
        s.append(h)

j.sort()
s.sort()
for i in range(1, H+1) :
    cnt = N//2 - bisect.bisect_left(s, i)
    cnt += bisect.bisect_right(j, i)
    answer.append(cnt)

answer.sort()
print(answer[0], answer.count(answer[0]))