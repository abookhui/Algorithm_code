# 현수막 silver 1
import sys
sys.setrecursionlimit(10**6)

n,m = map(int,input().split())

visited = [[0]*m for _ in range(n)]
d = [[1,0],[-1,0],[0,1],[0,-1],[1,1],[1,-1],[-1,1],[-1,-1]]

def dfs(x,y):
    visited[x][y] = 1

    for i in range(8):
        nx,ny = x+d[i][0], y+d[i][1]

        if 0<=nx<n and 0<=ny<m:
            if arr[nx][ny] == 1 and not visited[nx][ny]:
                dfs(nx,ny)
                visited[nx][ny] = 1


arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))

cnt = 0
for i in range(n):
    for j in range(m):
        if arr[i][j] == 1 and not visited[i][j]:
            dfs(i,j)
            cnt += 1
print(cnt)