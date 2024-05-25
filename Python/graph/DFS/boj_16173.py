# 점프왕 쩰리(Small) silver 4

import sys  
input = sys.stdin.readline

n = int(input())

graph = [list(map(int,input().split())) for _ in range(n)]
visited = [[0]*n for _ in range(n)]

flag = False
def dfs(x,y):
    global flag
    visited[x][y] = 1
    k = graph[x][y]

    for nx,ny in [[x+k,y],[x,y+k]]:
        if nx == n-1 and ny == n-1:
            flag = True
            break
        elif 0<=nx<n and 0<=ny<n:
            if not visited[nx][ny] and not flag:
                dfs(nx,ny)
    visited[x][y] = 0
    if flag : return

dfs(0,0)
if flag : print("HaruHaru")
else : print('Hing')

