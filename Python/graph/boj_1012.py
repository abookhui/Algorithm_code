#유기농 배추
import sys
sys.setrecursionlimit(10**6) # 재귀 깊이 설정 

dx =[1,-1,0,0]
dy =[0,0,1,-1]

def dfs(x, y):
    arr[x][y] = 0

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx >= 0 and ny >= 0 and nx < n and ny < m:
            if arr[nx][ny]:
                dfs(nx,ny)


for _ in range(int(input())):
    m, n, k = map(int, input().split())
    arr = [[0] * m for _ in range(n)]

    for _ in range(k):
        b, a = map(int, input().split())
        arr[a][b] = 1

    cnt = 0    
    for i in range(n):
        for j in range(m):
            if arr[i][j]:
                dfs(i, j)
                cnt += 1
    print(cnt)