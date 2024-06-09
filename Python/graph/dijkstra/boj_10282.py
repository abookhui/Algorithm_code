# 해킹 10282 - gold 4

import sys
from heapq import heappush,heappop
from collections import defaultdict
input = sys.stdin.readline

def dij(start,dist):
    que = []

    heappush(que,(0,start))
    dist[start] =0

    while que:
        cost,node = heappop(que)
        if cost > dist[node]: continue

        for nn,nd in com[node]:
            ncost = nd + dist[node]
            if ncost < dist[nn]:
                dist[nn] = ncost
                heappush(que,(ncost,nn))

    


for tc in range(int(input())):
    n,d,c = map(int,input().split())

    com = defaultdict(list)
    for _ in range(d):
        a,b,s = map(int,input().split())
        com[b].append([a,s])

    dist = [float('inf')] * (n+1)
    dij(c,dist)

    cnt = ans = 0
    for i in dist:
        if i !=float('inf') :
            cnt += 1
            ans = max(ans,i)
    print(cnt,ans)


    

