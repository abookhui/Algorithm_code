# 미로 탈출 14923 - gold 4
from collections import deque
import sys
input = sys.stdin.readline

n,m = map(int,input().split())
hx,hy = map(int,input().split())
ex,ey = map(int,input().split())

arr = [list(map(int,input().split())) for _ in range(n)]

flag = 0
if arr[hx-1][hy-1] == 1: flag = 1
que = deque([[hx-1,hy-1,flag,0]])

visited = [[0]*m for _ in range(n)]
visited_w = [[0]*m for _ in range(n)]
d = [[0,1],[0,-1],[1,0],[-1,0]]
visited[0][0] = 0

# 좌표가 0 이면 평소처럼 이동
# 만약 좌표가 1이면 이미 벽 부시기를 한 상태인지 확인
# 아니라면 벽 부수기, 이후로는 못 부심 que 넣을때 0으로 넣어주기
# 벽을 부순 이후는 visited_w를 아직 벽을 안 부수었다면 visited에 방문확인해줘 꼬이는 일 없게하기

while que:
    x,y,chk,cnt = que.popleft()

    if x==ex-1 and y==ey-1:
        break

    for i in range(4):
        nx,ny = x+d[i][0],y+d[i][1]

        if 0<=nx<n and 0<=ny<m:
            if arr[nx][ny] == 0:
                if chk and not visited_w[nx][ny]: 
                    visited_w[nx][ny] = visited_w[x][y] + 1
                    que.append([nx,ny,chk,cnt+1])
                elif not chk and not visited[nx][ny]: 
                    visited[nx][ny] = visited[x][y] + 1
                    que.append([nx,ny,chk,cnt+1])
                
            elif arr[nx][ny] == 1 and not visited_w[nx][ny]:
                if not chk : # 아직 벽 부순적 X
                    que.appendleft([nx,ny,1,cnt+1])
                    visited_w[nx][ny] = visited_w[x][y] + 1

if visited[ex-1][ey-1] or visited_w[ex-1][ey-1]: print(cnt)
else : print(-1)