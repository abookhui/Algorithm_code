import sys
from collections import deque,defaultdict
from heapq import heappop,heappush
input = sys.stdin.readline

m,n = map(int,input().split())

maze = [list(map(int,input().rstrip())) for _ in range(n)]

def dij(a,b):
    que = []
    heappush(que,(0,a,b))
    cnt = [[float('inf')] * m for _ in range(n)]
    cnt[a][b] =0

    while que:
        cost,x,y = heappop(que)

        if cost > cnt[x][y]: continue

        for nx,ny in [[x+1,y],[x,y-1],[x-1,y],[x,y+1]]:
            if not (0<=nx<n and 0<=ny<m): continue

            ncost = cost + maze[nx][ny]
            if ncost < cnt[nx][ny]: 
                cnt[nx][ny] = ncost
                heappush(que,(ncost,nx,ny))
    return cnt[n-1][m-1]
ans = dij(0,0)
if ans==float('inf'): print(0)  
else : print(ans)