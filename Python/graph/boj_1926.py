n,m = map(int,input().split())

visited = [[False]*m for _ in range(n)]
d = [[1,0],[-1,0],[0,1],[0,-1]]

def dfs(a,b):
    visited[a][b] = True

    stack = [[a,b]]
    ans = 0
    while stack:
        ans += 1
        x,y = stack.pop()
        for i in range(4):
            nx, ny = x+d[i][0], y+d[i][1]

            if 0<=nx<n and 0<=ny<m:
                if not visited[nx][ny] and arr[nx][ny] == 1:
                    stack.append([nx,ny])
                    visited[nx][ny] = True
    return ans

arr = []
for _ in range(n):
    tmp = list(map(int,input().split()))
    arr.append(tmp)

cnt = 0
ans = 0
for i in range(n):
    for j in range(m):
        if arr[i][j] == 1 and not visited[i][j]:
            ans = max(dfs(i,j),ans)
            cnt+=1
print(cnt)
print(ans)