# 빙산 2573 gold 4
# 1. 빙산 녹이기
# 2. 빙산이 몇 조각인지 확인
# 2.1 빙산이 2조각 이상이면 끝내기

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def melt(x,y):
    visited[x][y] = 1
    for i in range(4):
        nx, ny = x + dx[i], y+dy[i]

        if 0<= nx <n and 0<= ny <m:
            if arr[nx][ny]==0 and not visited[nx][ny]:
                arr[x][y]-=1
                if arr[x][y] <=0:
                    arr[x][y]=0
                    break
    
def dfs(x,y):
    visited[x][y] = 1

    stack = []
    stack.append([x,y])

    while stack:
        a,b = stack.pop()

        for i in range(4):
            nx, ny = a + dx[i], b+dy[i]

            if 0<= nx <n and 0<= ny <m:
                if arr[nx][ny] > 0 and not visited[nx][ny]:
                    stack.append([nx,ny])
                    visited[nx][ny] = 1



n,m = map(int,input().split())

arr = []

for i in range(n):
    arr.append(list(map(int,input().split())))

years = 0
cnt = 0
flag = False
while cnt < 2:
    visited = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if arr[i][j] > 0:
                melt(i,j)
    visited = [[0]*m for _ in range(n)]

    cnt = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] > 0 and not visited[i][j]:
                dfs(i,j)
                cnt+=1
    if cnt == 0:
        flag = True
        break
        
    years+=1
        
if flag: print(0)   
else : print(years)