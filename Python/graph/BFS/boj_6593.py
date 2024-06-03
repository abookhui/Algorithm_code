# 상범 빌딩 6593 - gold 5

import sys
from collections import deque
input = sys.stdin.readline

while True:
    l,r,c = map(int,input().split())

    if l==0 : break

    building = []

    for i in range(l):
        arr = [list(map(str,input().rstrip())) for _ in range(r)]
        enter = input()
        building.append(arr)
    
    que = deque()
    flag = False
    for i in range(l):
        for j in range(r):
            for k in range(c):
                if building[i][j][k] == 'S':
                    que.append([i,j,k])
                    break
                elif building[i][j][k] == 'E':
                    lev,a,b = i,j,k
                    flag = True
        if que and flag: break
    
    visited = [[[0]*c for row in range(r)] for dep in range(l)]


    while que:
        z,x,y = que.popleft()

        if building[z][x][y] == 'E':
            break
        for nz,nx,ny in [[z,x,y+1],[z,x,y-1],[z,x+1,y],[z,x-1,y],[z+1,x,y],[z-1,x,y]]:
            if 0<=nz<l and 0<=nx<r and 0<=ny<c:
                if not visited[nz][nx][ny] and building[nz][nx][ny] !='#':
                    que.append([nz,nx,ny])
                    visited[nz][nx][ny] = visited[z][x][y] + 1
    
    if visited[lev][a][b]: print('Escaped in',visited[lev][a][b],'minute(s).')
    else : print('Trapped!')

