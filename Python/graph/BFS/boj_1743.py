# 음식물 피하기 silver 1

from collections import deque
import sys
input = sys.stdin.readline

n,m,k = map(int,input().split())
trash = deque()

graph = [[0]*m for _ in range(n)]
visited = [[False]*m for _ in range(n)]
d = [[0,1],[0,-1],[1,0],[-1,0]]

def bfs(a,b):
    que = deque([[a,b]])

    answer = 0
    while que:
        x,y = que.popleft()

        for i in range(4):
            nx,ny = x+d[i][0], y+d[i][1]    

            if 0<=nx<n and 0<=ny<m :
                if not visited[nx][ny] and graph[nx][ny]:
                    visited[nx][ny] = True
                    answer+=1
                    que.append([nx,ny]) 
    return answer


for _ in range(k):
    a,b = map(int,input().split())
    graph[a-1][b-1]  = 1
    trash.append([a-1,b-1])

result = 1
while trash:
    cx,cy = trash.popleft()
    result = max(bfs(cx,cy),result)


print(result)

