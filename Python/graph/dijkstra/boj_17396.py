import sys
from collections import deque,defaultdict
import heapq
input = sys.stdin.readline

n,m = map(int,input().split())

wad = list(map(int,input().split()))
graph = defaultdict(list)
dist = [-1]*n
for _ in range(m):
    a,b,t = map(int,input().split())
    graph[a].append([b,t])
    graph[b].append([a,t])

def dijkstra(start):
    que = []
    heapq.heappush(que,(0,start))
    dist[start] = 0

    while que:
        d,node = heapq.heappop(que)
        if wad[node] or d > dist[node]: continue

        for nn,nd in graph[node]:
            cost = nd+dist[node]
            if dist[nn] == -1 :
                dist[nn] = cost
                heapq.heappush(que,(cost,nn))
            elif cost < dist[nn]:
                dist[nn] = cost
                heapq.heappush(que,(cost,nn))
dijkstra(0) 
print(dist[n-1])