# 아기 상어 16236 - gold 3
# 시간 초과 >> 

from collections import deque
import sys
input = sys.stdin.readline

n = int(input())

graph = [list(map(int,input().split())) for _ in range(n)]


for i in range(n):
    for j in range(n):
        if graph[i][j] == 9:
            sx,sy,size = i,j,2

d = [[-1,0],[0,-1],[0,1],[1,0]]


def bfs(a,b,size):
    visited = [[0]*n for _ in range(n)]
    que = deque([[a,b]])
    
    answer = []
    while que:
        x,y = que.popleft()

        for i in range(4):
            nx,ny = x+d[i][0], y+d[i][1]

            if 0<=nx<n and 0<=ny<n and not visited[nx][ny]:
                if graph[nx][ny] <= size:
                    visited[nx][ny] = visited[x][y] + 1
                    que.append([nx,ny])
                    if graph[nx][ny] < size and graph[nx][ny]>0:
                        answer.append([nx,ny,visited[nx][ny]])

    answer = sorted(answer, key = lambda x: (-x[2],-x[0],-x[1]))
    return answer

cnt = time = 0

while True:
    shark = bfs(sx,sy,size)

    if len(shark) == 0: break

    nx,ny,dist = shark.pop()
    time += dist
    graph[nx][ny] = graph[sx][sy] = 0
    sx,sy = nx,ny

    cnt+=1
    if cnt == size:
        size+=1 
        cnt = 0

print(time)