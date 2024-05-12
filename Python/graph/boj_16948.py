from collections import deque

n = int(input())
r1,c1,r2,c2 = map(int,input().split())

visited = [[0]*n for _ in range(n)]

que = deque()
que.append([r1,c1])

d = [[-2,-1],[-2,1],[0,-2],[0,2],[2,-1],[2,1]]
flag = True
while que:
    x,y = que.popleft()
    if not flag: break
    for i in range(6):
        nx,ny = x+d[i][0], y+d[i][1]    
        if nx == r2 and ny == c2 and flag:
            flag = False
            visited[nx][ny] = visited[x][y] +1
            break
        elif 0<=nx<n and 0<=ny<n and not visited[nx][ny]:
            visited[nx][ny] = visited[x][y] +1
            que.append([nx,ny])
        
if flag : print(-1)
else : print(visited[r2][c2])


