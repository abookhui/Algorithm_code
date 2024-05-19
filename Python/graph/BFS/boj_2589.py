# 보물섬 gold 5
from collections import deque

n,m = map(int,input().split())
d = [[1,0],[-1,0],[0,1],[0,-1]]

arr = []
land= []
for i in range(n):
    tmp = []
    line = input()
    for j in range(m):
        if line[j] == 'L': land.append([i,j])
        tmp.append(line[j])
        
    arr.append(tmp)

ans = 0
while land:
    visited = [[0]*m for _ in range(n)]
    que = deque()
    a,b = land.pop()
    que.append([a,b])
    cnt = 0
    while que:
        x,y = que.popleft()
        
        for i in range(4):
            nx,ny = x+d[i][0],y+d[i][1] 

            if 0<=nx<n and 0<=ny<m:
                if not visited[nx][ny] and arr[nx][ny] == 'L' and not(nx == a and ny == b) :
                    visited[nx][ny] = visited[x][y]+1
                    que.append([nx,ny])
    ans = max(ans,max(map(max,visited)))

print(ans)