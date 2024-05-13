# 토마토 gold 5
import sys
input = sys.stdin.readline 
from collections import deque

m,n,h = map(int,input().split())

arr = []
visited = []
for i in range(h):
    tmp = [[0]*m for _ in range(n)]
    visited.append(tmp)
que = deque()
for k in range(h):
    tmp = []
    for i in range(n):
        tmp.append(list(map(int,input().split())))
        for j in range(m):
            if tmp[i][j] == 1 : 
                que.append([k,i,j])
    
    arr.append(tmp)

d = [[0,1,0],[0,-1,0],[0,0,1],[0,0,-1],[1,0,0],[-1,0,0]]

while que:
    z,x,y = que.popleft()

    for i in range(6):
        nz,nx,ny = z+d[i][0],x+d[i][1],y+d[i][2]   

        if 0<=nx<n and 0<=ny<m and 0<=nz<h:
            if not visited[nz][nx][ny] and arr[nz][nx][ny] == 0:
                visited[nz][nx][ny] = visited[z][x][y] + 1
                que.append([nz,nx,ny])

ans = 0
flag = False
for k in range(h):
    for i in range(n):
        for j in range(m):
            if visited[k][i][j] == 0:
                if arr[k][i][j] == 0 :
                    print(-1)
                    flag = True
                    break
            else : ans = max(ans,visited[k][i][j])
        if flag: break
    if flag: break
                    
if not flag: print(ans)
