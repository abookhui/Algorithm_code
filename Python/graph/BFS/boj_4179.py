# 불 !

import sys
from collections import deque

dx =[0,-1,1,0]
dy =[1,0,0,-1]
r,c = map(int,input().split())
visited_j =[[0]*c for _ in range(r)]
visited_f =[[0]*c for _ in range(r)]
jh = deque()
fire = deque()

def bfs():

    while fire:
        x,y = fire.popleft()

        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]

            if 0<=nx<r and 0<=ny<c:
                if not arr[nx][ny] == '#' and not visited_f[nx][ny]:
                    visited_f[nx][ny] = visited_f[x][y] + 1
                    fire.append([nx,ny])
    
    while jh:
        x,y = jh.popleft()

        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]

            if 0<=nx<r and 0<=ny<c:
                if not arr[nx][ny]=='#' and not visited_j[nx][ny]:
                    if not visited_f[nx][ny] or visited_f[nx][ny] > visited_j[x][y] + 1:
                        visited_j[nx][ny] = visited_j[x][y]+1
                        jh.append([nx,ny])

            else : return visited_j[x][y]
                

    return "IMPOSSIBLE"
arr = []    


for i in range(r):
    tmp = []
    line = input()
    for j in range(len(line)):
        tmp.append(line[j])
        if line[j] == 'J': 
            visited_j[i][j] = 1 
            jh.append([i,j])
        if line[j] == 'F': 
            visited_f[i][j] = 1
            fire.append([i,j])

    arr.append(tmp)

print(bfs())

                    
