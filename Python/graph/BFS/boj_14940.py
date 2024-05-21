# 쉬운 최단거리 

from collections import deque
import sys
input = sys.stdin.readline

d = [[0,1],[0,-1],[1,0],[-1,0]]

n,m = map(int,input().split())

arr = [list(map(int,input().split())) for _ in range(n)]
visited = [[False]*m for _ in range(n)]
dist = [[0]*m for _ in range(n)]

que = deque()

for i in range(n):
    for j in range(m):
        if arr[i][j] == 2:
            que.append([i,j])
            visited[i][j] = True
            break

while que:
    x,y = que.popleft()

    for i in range(4):
        nx,ny = x+d[i][0],y+d[i][1] 

        if 0<=nx<n and 0<=ny<m and not visited[nx][ny]:
            if not dist[nx][ny] and arr[nx][ny] == 1:
                visited[nx][ny] = True
                dist[nx][ny] = dist[x][y] +1
                que.append([nx,ny])

for i in range(n):
    for j in range(m):
        if visited[i][j]:
            if arr[i][j] == 1: print(dist[i][j],end=" ")
            elif arr[i][j] ==2: print(0, end=" ")
        else :
            print(-1 if arr[i][j] == 1 else 0, end=" ")
    print()