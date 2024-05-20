# 컴백홈 1189 - silver 1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

r,c,k = map(int,input().split())
graph = [list(map(str,input().rstrip())) for _ in range(r)]

d = [[0,1],[0,-1],[1,0],[-1,0]]
visited = [[0]*c for _ in range(r)]
visited[r-1][0] = 1

cnt = 0
def dfs(x,y):
    global cnt
    if x == 0 and y == c-1:
        if visited[x][y] == k:
            cnt+=1
        return
    for i in range(4):
        nx,ny = x+d[i][0],y+d[i][1]

        if 0<=nx<r and 0<=ny<c :
            if not visited[nx][ny] and graph[nx][ny] == '.':
                visited[nx][ny] = visited[x][y] + 1
                dfs(nx,ny)
                visited[nx][ny] = 0

dfs(r-1,0)
print(cnt)