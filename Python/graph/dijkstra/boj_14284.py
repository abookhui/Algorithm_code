# 간선 이어가기2 14284 - gold 5

import sys
from collections import defaultdict
from heapq import heappop, heappush
input = sys.stdin.readline

n,m = map(int,input().split())

graph = defaultdict(list)
for _ in range(m):
    a,b,c = map(int,input().split())
    graph[a].append([b,c])
    graph[b].append([a,c])

s,e = map(int,input().split())

def dij(start,end):
    dist = [float('inf')] * (n+1)
    dist[start] =0 
    que = []
    heappush(que,(0,start))

    while(que):
        cost,node = heappop(que)
        if cost > dist[node]: continue

        for nn,nd in graph[node]:
            ncost = nd+dist[node]
            if ncost < dist[nn]:
                dist[nn] = ncost
                heappush(que,(ncost,nn))
    return dist[end]

print(dij(s,e))
