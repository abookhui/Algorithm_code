# 전쟁-전투 silver 1
from collections import deque

m,n = map(int,input().split())
visited = [[0]*m for _ in range(n)]

arr = []
w = deque()
b = deque()

d = [[1,0],[-1,0],[0,1],[0,-1]]

ans = 0
def dfs(x,y,color):
    global ans
    for i in range(4):
        nx, ny= x+d[i][0],y+d[i][1] 

        if 0<=nx<n and 0<=ny<m:
            if not visited[nx][ny] and arr[nx][ny] == color:
                visited[nx][ny] = 1
                dfs(nx,ny,color)
                ans += 1
    return ans

for i in range(n):
    line = input()
    tmp = [] 
    for j in range(m):
        tmp.append(line[j])
    arr.append(tmp)


cnt_w =0
cnt_b =0
for i in range(n):
    for j in range(m):
        if not visited[i][j]:
            if arr[i][j] == 'W':
                cnt = dfs(i,j,'W')
                if cnt == 0 : cnt = 1
                cnt_w += cnt**2
                ans = 0
            elif arr[i][j] == 'B':
                cnt = dfs(i,j,'B')
                if cnt == 0 : cnt = 1
                cnt_b += cnt**2
                ans = 0
print(cnt_w)
print(cnt_b)                