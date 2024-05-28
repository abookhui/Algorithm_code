# 항체 인식 22352 - gold 5
import sys  
from collections import defaultdict
from collections import deque
input = sys.stdin.readline

n,m = map(int,input().split())

before = [list(map(int,input().split())) for _ in range(n)]
after = [list(map(int,input().split())) for _ in range(n)]
visited = [[0]*m for _ in range(n)]

def bfs(a,b,num,pre):
    que = deque([[a,b]])
    visited[a][b] = 1
    num = before[a][b]

    while que:
        x,y = que.popleft()
        
        for nx,ny in [[x+1,y],[x-1,y],[x,y+1],[x,y-1]]:
            if 0<=nx<n and 0<=ny<m:
                if not visited[nx][ny] and before[nx][ny] == pre:
                    que.append([nx,ny])
                    before[nx][ny] = num
                    visited[nx][ny] = 1
        
flag = True
for i in range(n):
    for j in range(m):
        if before[i][j] != after[i][j] and not visited[i][j]:
            tmp = before[i][j]
            before[i][j] = after[i][j]
            bfs(i,j,after[i][j],tmp)
            flag = False
            break
    if not flag: break
      

for i in range(n):
    for j in range(m):
        if before[i][j] != after[i][j]:
            print("NO")
            exit()

print('YES')

