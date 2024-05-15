# 공주님을 구해라! gold 5
# indexError >> visited 범위 값을 잘못줌 
# 조건이 너무 많아서 복잡함 >> 이리 저리 꼬여서 다시 했는데도 조건이 많음..

from collections import deque
import sys
input =sys.stdin.readline

n,m,t = map(int,input().split())
visited = [[0]*m for _ in range(n)]

arr = [list(map(int,input().split())) for _ in range(n)]

que = deque([[0,0]])
gram = deque()
for i in range(n):
    for j in range(m):    
        if arr[i][j] == 2:
            gram.append([i,j])


d = [[1,0],[-1,0],[0,1],[0,-1]]

while que:
    x,y = que.popleft()

    for i in range(4):
        nx,ny = x+d[i][0], y+d[i][1]
            
        if 0<=nx<n and 0<=ny<m:
            if not visited[nx][ny] and arr[nx][ny] != 1:
                que.append([nx,ny])
                visited[nx][ny] = visited[x][y] + 1

if visited[n-1][m-1] : cmp = visited[n-1][m-1]
else : cmp = -1

gi,gj = gram.pop()
if visited[gi][gj]: time = visited[gi][gj]
else : time = -1


visited = [[0]*m for _ in range(n)]
gram.appendleft([gi,gj])
while gram:
    x,y = gram.popleft()

    for i in range(4):
        nx,ny = x+d[i][0], y+d[i][1]
            
        if 0<=nx<n and 0<=ny<m:
            if not visited[nx][ny]:
                gram.append([nx,ny])
                visited[nx][ny] = visited[x][y] + 1
    if visited[n-1][m-1]: break

if cmp>0 and time>0: ans = min(cmp,time+visited[n-1][m-1])
elif cmp > 0 and time < 0 : ans = cmp
elif cmp < 0 and time > 0 : ans =time+visited[n-1][m-1]
else : ans = -1

if ans<=t and ans > 0: print(ans)
else : print('Fail')
