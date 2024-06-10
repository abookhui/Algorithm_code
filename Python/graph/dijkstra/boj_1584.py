# 게임 1584 - gold 5

import sys
from collections import defaultdict
from heapq import heappop, heappush
input = sys.stdin.readline
# 1,3 3,2

#  0 1 2 3
#0 0 0 0 0
#1 0 0 0 *
#2 0 0 0 0
#3 0 0 * 0
# row: 1,3 col: 3 2 1<col<2 and 1<row<3
n = int(input())
graph = [[0]*501 for _ in range(501)]

def chk(x1,x2,y1,y2,num):
    for i in range(x1,x2+1):
        for j in range(y1,y2+1):
            if graph[i][j] < num:
                graph[i][j] = num

for i in range(n):
    a,b,c,d = map(int,input().split())  
    x1,x2= min(a,c),max(a,c)
    y1,y2 = min(b,d),max(b,d)
    chk(x1,x2,y1,y2,1)
m = int(input())

for i in range(m):
    a,b,c,d = map(int,input().split())  
    x1,x2= min(a,c),max(a,c)
    y1,y2 = min(b,d),max(b,d)
    chk(x1,x2,y1,y2,2)

def dij():
    dist = [[float('inf')] * 501 for _ in range(501)]
    dist[0][0] = 0
    que = [] 
    heappush(que,(0,0,0))

    while que:
        cost,x,y = heappop(que)
        if cost > dist[x][y]: continue

        for nx,ny in [[x+1,y],[x,y-1],[x-1,y],[x,y+1]]:
            if not (0<=nx<501 and 0<=ny<501): continue
            if graph[nx][ny] ==2: continue
            ncost = graph[nx][ny] + dist[x][y]
            if ncost < dist[nx][ny]: 
                dist[nx][ny] = ncost
                heappush(que,(ncost,nx,ny))
    ans = dist[500][500]
    if ans == float('inf'): return -1
    return ans

print(dij())



            