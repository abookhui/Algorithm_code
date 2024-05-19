# 로봇 1726 - gold 3
# 다음 방문횟수와 현재 방문횟수가 같아도 넣어줌 
# 하지만 다 넣어줘 버리면 메모리 초과,시간초과가 나기에 목적지일때면 비교해서 넣어주기

from collections import deque
import sys
input = sys.stdin.readline

n,m = map(int,input().split())
graph = [list(map(int,input().split())) for _ in range(n)]

sx,sy,sd = map(int,input().split()) 
ex,ey,ed = map(int,input().split())

que = deque([[sx-1,sy-1,sd-1,0]])
visited = [[0]*m for _ in range(n)]
visited[sx-1][sy-1] = 100

def turn(pre,next):
    ans = {0: [0,2,1,1], 1:[2,0,1,1],2:[1,1,0,2],3:[1,1,2,0]}.get(pre)
    return ans[next]

dx = [0,0,0,0,0,0,1,2,3,-1,-2,-3]
dy = [1,2,3,-1,-2,-3,0,0,0,0,0,0]
# 동 서 남 북
# 0  1  2  3

result = 0
flag = 0

while que:
    x,y,d,cnt = que.popleft()

    if x==ex-1 and y==ey-1:
        if not flag: 
            result = cnt+turn(d,ed-1)
            flag = 1
        else : result = min(result,cnt+turn(d,ed-1))

    idx=0
    while idx<12:
        tmp = idx//3 # 0:동, 1:서, 2:남, 3:북
        nx,ny,nd = x+dx[idx],y+dy[idx],tmp

        if 0<=nx<n and 0<=ny<m and graph[nx][ny] == 0 and not(nx==sx-1 and ny==sy-1):
            move = cnt + turn(d,nd) + 1
            if not visited[nx][ny] or (visited[nx][ny] and visited[nx][ny] > move) or (nx==ex-1 and ny==ey-1 and visited[nx][ny] == move):
                visited[nx][ny] = move
                que.append([nx,ny,nd,move])
            idx+=1
        elif 0<=nx<n and 0<=ny<m and graph[nx][ny] == 1: idx = (tmp+1)*3
        else : idx = (tmp+1)*3
    
print(result)