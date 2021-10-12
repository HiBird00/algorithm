import sys
import heapq

N = int(sys.stdin.readline())
lectures = []
for _ in range(N) :
    s, t = map(int, sys.stdin.readline().split())
    lectures.append([s, t])

lectures.sort()
classes = []

for i in range(N) :
    if len(classes) and classes[0] <= lectures[i][0] :
        heapq.heappop(classes)
    heapq.heappush(classes, lectures[i][1])

print(len(classes))