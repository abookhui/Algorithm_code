# 택배 1719 - gold 3

import sys
from collections import defaultdict
from heapq import heappop, heappush
input = sys.stdin.readline

n,m = map(int,input().split())

graph = defaultdict(list)
for _ in range(m):
    a,b,d = map(int,input().split())    
    graph[a].append([b,d])
    graph[b].append([a,d])

def dij(start):
    dist = [float('inf')] * (n+1)
    que = []
    heappush(que,(0,start))
    dist[start] = 0 
    parents = defaultdict()
    for i in range(1,n+1): parents[i] = i

    while que:
        cost,node = heappop(que)

        if cost > dist[node]: continue

        for nn,nd in graph[node]:
            ncost = nd + dist[node]
            if ncost < dist[nn]:
                dist[nn] = ncost
                heappush(que,(ncost,nn))
                parents[nn] = node
    #print(parents)
    for i in range(1,n+1):
        if i == start: print('-',end=" ")   
        else:
            cur = i
            while parents[cur] != start:
                cur = parents[cur]
            print(str(cur),end=" ")
    print() 

for i in range(1,n+1):
    dij(i)

