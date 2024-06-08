# 특정한 최단 경로 1504 - gold 4
import sys
from collections import deque,defaultdict
import heapq
input = sys.stdin.readline

n,e = map(int,input().split())

graph = defaultdict(list)
for _ in range(e):
    a,b,c = map(int,input().split())    
    graph[a].append([b,c])
    graph[b].append([a,c])      

stop = list(map(int,input().split()))


def dij(start,stop):
    dist = [-1] * (n+1)

    que = []
    heapq.heappush(que,(0,start))
    dist[start] = 0

    while que:
        cost,node = heapq.heappop(que)

        if cost > dist[node]: continue

        for nn,nd in graph[node]:
            ncost = nd + dist[node]
            if dist[nn] == -1 : 
                dist[nn] = ncost
                heapq.heappush(que,(ncost,nn))
            elif dist[nn] > ncost :
                dist[nn] =ncost
                heapq.heappush(que,(ncost,nn))
    return dist[stop] 

ans1 = [dij(1,stop[0]),dij(stop[0],stop[1]),dij(stop[1],n)]
ans2 = [dij(1,stop[1]),dij(stop[1],stop[0]),dij(stop[0],n)]
if -1 in ans1 and -1 in ans2: print(-1)
else : print(min(sum(ans1),sum(ans2)))