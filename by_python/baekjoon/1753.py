import sys
import heapq
input = sys.stdin.readline
INF = sys.maxsize
V, E = map(int, input().split())
K = int(input())
graph = [[] for _ in range(V+1)]
heap = []
dist = [INF for _ in range(V+1)]

for i in range(E) :
    u, v, w = map(int, input().split())
    graph[u].append((v, w))


dist[K] = 0
heapq.heappush(heap, (0, K))

while heap :
    weight, now = heapq.heappop(heap)

    for vi, wi in graph[now] :
        nextWeight = dist[now] + wi
        if nextWeight < dist[vi] :
            dist[vi] = nextWeight
            heapq.heappush(heap, (nextWeight, vi))

for ret in dist[1:] :
    if ret == INF :
        print('INF')
    else :
        print(ret)


