# 미로만들기 gold 4
import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
arr=[list(map(int,input().rstrip())) for _ in range(n)]

visited = [[10**9]*n for _ in range(n)]
visited[0][0] = 0
que = deque()
que.append([0,0])

d = [[0,1],[0,-1],[1,0],[-1,0]]
while que:
    x,y = que.popleft()

    for i in range(4):
        nx,ny = x+d[i][0],y+d[i][1] 

        if 0<=nx<n and 0<=ny<n:
            if arr[nx][ny] == 1 and visited[nx][ny] > visited[x][y]:
                visited[nx][ny] = visited[x][y]
                que.append([nx,ny])
            elif arr[nx][ny] == 0 and visited[nx][ny] > visited[x][y]:
                visited[nx][ny] = visited[x][y] + 1
                que.append([nx,ny])

print(visited[n-1][n-1])