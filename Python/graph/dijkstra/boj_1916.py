import sys
from collections import deque,defaultdict
import heapq
input = sys.stdin.readline


n =int(input())
m = int(input())
dist = [-1] * (n+1)
graph = defaultdict(list)
visited = [-1] * (n+1)
for _ in range(m):
    a,b,cost = map(int,input().split())
    graph[a].append([b,cost])
    #graph[b].append([a,cost])

s,e = map(int,input().split())

def dijkstra(start):
    que = []
    heapq.heappush(que,(0,start))
    dist[start] = 0

    while que:
        d,node = heapq.heappop(que)
        if d > dist[node] : continue

        for nn,nd in graph[node]:
            ncost = nd + dist[node]
            if dist[nn] == -1 :
                dist[nn] = ncost
                heapq.heappush(que,(ncost,nn))
            elif ncost < dist[nn]:
                dist[nn] = ncost
                heapq.heappush(que,(ncost,nn))


dijkstra(s)
print(dist[e])


       

