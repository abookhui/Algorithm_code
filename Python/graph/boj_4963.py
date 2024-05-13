import sys
from collections import deque
input = sys.stdin.readline

d = [[1,0],[-1,0],[0,1],[0,-1],[1,1],[1,-1],[-1,1],[-1,-1]]

def bfs(a,b):
    que = deque()
    que.append([a,b])

    while que:
        x,y = que.popleft()

        for i in range(8):
            nx,ny = x+d[i][0],y+d[i][1] 

            if 0<=nx<h and 0<=ny<w and not visited[nx][ny] and arr[nx][ny] == 1:
                que.append([nx,ny])
                visited[nx][ny] = 1
while True:
    w,h = map(int,input().split())

    if w == 0 and h == 0: break
    visited = [[0]*w for _ in range(h)]

    arr = []
    for i in range(h):
        arr.append(list(map(int,input().split())))

    ans = 0
    for i in range(h):
        for j in range(w):
            if arr[i][j] == 1 and not visited[i][j]:
                bfs(i,j)
                ans += 1
    print(ans)