# 점프왕 쩰리 (Large) 16174 - silver 1

from collections import deque
import sys
input = sys.stdin.readline

n = int(input())

map = [list(map(int,input().split())) for _ in range(n)]

visited = [[0]*n for _ in range(n)]

def bfs():
    que = deque([[0,0]])
    flag = False
    while que:
        x,y = que.popleft()
        k = map[x][y]
        if x==n-1 and y==n-1:
            flag = True
            break
        for d in [[k,0],[0,k]] :
            nx,ny = x+d[0],y+d[1]

            if 0<=nx<n and 0<=ny<n :
                if not visited[nx][ny]:
                    que.append([nx,ny])
                    visited[nx][ny] = 1
    return flag


print('HaruHaru' if bfs() else 'Hing' )