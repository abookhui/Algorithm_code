# 면접보는 승범이네 17835 - gold 2

import sys
from collections import defaultdict
from heapq import heappush, heappop
input = sys.stdin.readline

n,m,k = map(int,input().split())

city = defaultdict(list)
for _ in range(m):
    u,v,c = map(int,input().split())
    city[v].append([u,c])

target =list(map(int,input().split()))

def dij():
    dist = [float('inf')] * (n+1)
    que = [] 

    for i in target:
        heappush(que,(0,i))
        dist[i] = 0

    while que:
        cost,node = heappop(que)
        if cost > dist[node]: continue

        for nn,nd in city[node]:
            ncost = nd + dist[node]
            if ncost < dist[nn]:
                dist[nn] = ncost
                heappush(que,(ncost,nn))
    return dist
    

ans=ans_idx = 0

d = dij()

for i in range(1,n+1):
    if d[i] > ans: ans,ans_idx = d[i],i

print(ans_idx)    
print(ans)
