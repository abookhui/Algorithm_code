# 창영이와 퇴근 22116 - gold 4

import sys
from collections import deque,defaultdict
import heapq
input = sys.stdin.readline

n = int(input())

graph = [list(map(int,input().split())) for _ in range(n)]
dist = [[-1] * n for _ in range(n)]

def dijkstra(a,b,slope):
    que = []
    heapq.heappush(que,(slope,a,b))   
    dist[a][b] = 0

    while que:
        s,x,y = heapq.heappop(que)
        if s > dist[x][y] : continue

        for nx,ny in [[x+1,y],[x,y-1],[x-1,y],[x,y+1]]:
            if not (0<=nx<n and 0<=ny<n) : continue
            heigh = abs(graph[x][y] - graph[nx][ny])
            if heigh==0 : heigh = s
            heigh = max(heigh,s)
            if dist[nx][ny] == -1 :
                dist[nx][ny] = heigh
                heapq.heappush(que,(heigh,nx,ny))
            elif dist[nx][ny] > heigh:
                dist[nx][ny] = heigh
                heapq.heappush(que,(heigh,nx,ny))
dijkstra(0,0,0)
print(dist[n-1][n-1])