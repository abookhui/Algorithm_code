# 서강그라운드 14938 - gold 4

import sys
from collections import defaultdict
from heapq import heappop, heappush
input = sys.stdin.readline

def dij(start):
    dist = [float('inf')] * n
    dist[start] = 0 
    
    que =[]
    heappush(que,(0,start))

    while que:
        cost,node = heappop(que)

        if cost > dist[node]: continue

        for nn,nd in field[node]:
            ncost = nd + dist[node]
            if ncost < dist[nn]:
                dist[nn] = ncost
                heappush(que,(nd,nn))
    cnt = 0
    for i in range(len(dist)):
        if dist[i] <= m: cnt+=item[i]
    return cnt

n,m,r = map(int,input().split())    

item = list(map(int,input().split()))

field = defaultdict(list)
for _ in range(r):
    a,b,l = map(int,input().split())
    field[a-1].append([b-1,l])
    field[b-1].append([a-1,l])

ans = 0
for i in range(n):
    ans = max(ans,dij(i))

print(ans)

