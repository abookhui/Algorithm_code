# 군탈체포조 23354 - gold 3

import sys,itertools
from collections import deque,defaultdict
from heapq import heappush,heappop
input = sys.stdin.readline

n = int(input())
target =[]
arr =[]
for i in range(n):
    tmp = list(map(int,input().split()))
    for j in range(n):
        if tmp[j]==0 :
            target.append((i,j))
        elif tmp[j]==-1:
            home = (i,j)
            tmp[j] = 0
    arr.append(tmp)

if len(target) == 0:
    print(0)
    exit()

def dij(start):
    a,b = start

    dist = [[float("inf")] *n for _ in range(n)]
    dist[a][b] = 0 
    que = []
    heappush(que,(0,a,b))

    while que:
        cost,x,y = heappop(que)
        if cost > dist[x][y] : continue

        for nx,ny in [[x+1,y],[x,y-1],[x-1,y],[x,y+1]]:
            if not(0<=nx<n and 0<=ny<n) : continue
            ncost = arr[nx][ny]+cost
            if ncost < dist[nx][ny]:
                dist[nx][ny] = ncost
                heappush(que,(ncost,nx,ny))
    return dist

dists = {}
dists[home] = dij(home)

for node in target:
    dists[node] = dij(node)

nPr = itertools.permutations(target,len(target))

ans = float('inf') 
for order in nPr:
    total =0 
    cur = home # 부대
    for node in order: # 탈영
        x,y = node
        total += dists[cur][x][y]
        cur = node
    x,y = home
    total += dists[cur][x][y] # 복귀
    ans = min(ans,total)
        
print(ans)

