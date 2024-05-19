# 벽 부수고 이동하기 2206 - gold 3
from collections import deque
import sys
input = sys.stdin.readline

n,m = map(int,input().split())
arr = [list(map(int,input().rstrip())) for _ in range(n)]

visited = [[0]*m for _ in range(n)]
visited_w = [[0]*m for _ in range(n)]
visited[0][0]=visited_w[0][0]=1

d = [[1,0],[-1,0],[0,1],[0,-1]]
que = deque([[0,0,0]])

while que:
    x,y,chk = que.popleft()

    for i in range(4):
        nx,ny = x+d[i][0],y+d[i][1]

        if 0<=nx<n and 0<=ny<m:
            if chk == 0 and arr[nx][ny] == 0 and not visited[nx][ny]:
                visited[nx][ny] = visited[x][y] + 1
                que.append([nx,ny,chk])
            elif chk ==0 and arr[nx][ny] == 1 and not visited[nx][ny]:
                visited_w[nx][ny] = visited[x][y] + 1
                que.append([nx,ny,1])
            elif chk == 1 and arr[nx][ny] == 0 and not visited_w[nx][ny]:
                visited_w[nx][ny] = visited_w[x][y] + 1
                que.append([nx,ny,chk])

cross = visited_w[n-1][m-1]
walk = visited[n-1][m-1]

if cross and walk:print(min(cross,walk))
elif cross: print(cross)
elif walk : print(walk)
else : print(-1)
