# 비밀 모임 13424 - gold 4
import sys
from collections import defaultdict,deque
from heapq import heappop, heappush
input = sys.stdin.readline

def dij(start):
    dist = [float('inf')] * (n+1)
    dist[start] = 0

    que = []
    heappush(que,(0,start))
    
    while que:
        cost,node = heappop(que)
        if cost > dist[node]: continue

        for nn,nd in room[node]:
            ncost = nd + dist[node]
            if ncost < dist[nn]:
                dist[nn] = ncost
                heappush(que,(ncost,nn))
    return dist


for tc in range(int(input())):
    n,m = map(int,input().split())

    room = defaultdict(list)
    for _ in range(m):
        a,b,c = map(int,input().split())    
        room[a].append([b,c])
        room[b].append([a,c])

    k = int(input())
    f = list(map(int,input().split()))

    cnt = [0] *(n+1)
    for i in f:
        vi = dij(i)
        for j in range(1,n+1):
            cnt[j] += vi[j]
    
    min_val = float('inf')
    ans = 0
    for i in range(1,n+1):
        #if i in f:continue
        if min_val > cnt[i]:
            min_val = cnt[i]
            ans = i
    print(ans)
            