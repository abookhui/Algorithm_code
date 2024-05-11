# 탈출 gold 4
from collections import deque

d = [[1,0],[-1,0],[0,1],[0,-1]]

r,c = map(int,input().split())
visited_w = [[0]*c for _ in range(r)]
visited_h = [[0]*c for _ in range(r)]

arr = []
water = deque()
que = deque()



for i in range(r):
    tmp = []
    line = input()
    for j in range(c):
        cmp = line[j]
        if cmp == 'D': 
            point_r = i
            point_c = j
        elif cmp == 'S': 
            que.append([i,j])
            cmp = '.'
        elif cmp == '*': water.append([i,j])
        tmp.append(cmp) 
    arr.append(tmp)
def bfs():

    while water:
        x,y = water.popleft()

        for i in range(4):
            nx,ny = x+d[i][0], y+d[i][1]   

            if 0<=nx<r and 0<=ny<c:
                if not visited_w[nx][ny] and arr[nx][ny] =='.':
                    visited_w[nx][ny] = visited_w[x][y] + 1
                    water.append([nx,ny])
    
    while que:
        x,y = que.popleft()

        for i in range(4):
            nx,ny = x+d[i][0], y+d[i][1]

            if nx == point_r and ny == point_c:
                    return visited_h[x][y]+1
            
            elif 0<=nx<r and 0<=ny<c:
                if not visited_h[nx][ny] and arr[nx][ny] == '.':
                    if (visited_w[nx][ny] > visited_h[x][y] + 1) or not visited_w[nx][ny]:
                        visited_h[nx][ny] = visited_h[x][y] + 1
                        que.append([nx,ny])
                        
    return "KAKTUS"
print(bfs())
