import sys
from collections import deque
input = sys.stdin.readline

n,m = map(int,input().split())

graph = [list(map(int,input().rstrip())) for _ in range(n)]
visited = [[0]*m for _ in range(n)]

def bfs(a,b):
    que = deque([[a,b]])
    
    while que:
        x,y = que.popleft()

        for nx,ny in [[x,y-1],[x,y+1],[x+1,y],[x-1,y]]:
            if 0<=nx<n and 0<=ny<m :
                if not visited[nx][ny] and graph[nx][ny] == 0:
                    que.append([nx,ny])
                    visited[nx][ny] = 1
    
for i in range(m):
    if graph[0][i] == 0:
        bfs(0,i)

for i in range(m):
    idx = n-1 
    if visited[idx][i]: 
        print('YES')
        exit()
print('NO')