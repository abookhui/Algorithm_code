# 불 !
# dx =[0,-1,1,0]
# dy =[1,0,0,-1]
# n,m = map(int,input().split())

# arr =[]

# def change(c):
#     if c == '#': return 2
#     elif c == '.' : return 0
#     elif c == 'F' : return 3
#     elif c == 'J' : return 1        

# jh =[]
# fire = []
# for i in range(n):
#     tmp =[]
#     line = input()
#     for j in range(len(line)):  
#         num = change(line[j])

#         if num == 1: jh.append([1,i,j])
#         elif num == 3: fire.append([i,j])
#         tmp.append(num)
  
#     arr.append(tmp)

# flag = False
# cnt = 0
# visited = [[False] * m for _ in range(n)]
# cnt_arr = [[0] *m for _ in range(n)]
# cnt_arr = arr
# print(cnt_arr)
# ans=[]
# while jh:
#     c,jx,jy = jh.pop(0)
#     visited[jx][jy] = True

    
#     cnt = c + 1
#     nf = []
#     while fire:
#         fx, fy = fire.pop()
#         visited[fx][fy] = True
#         for i in range(4):
#             nfx = fx+dx[i]
#             nfy = fy+dy[i]

#             if nfx >= 0 and nfy >= 0 and nfx < n and nfy <m:
#                 if arr[nfx][nfy] == 0 or arr[nfx][nfy] == 1:
#                     if not visited[nfx][nfy]:
#                         arr[nfx][nfy] = 3
#                         cnt_arr[nfx][nfy] = 3
#                         nf.append([nfx,nfy])
#     fire.extend(nf)

#     for i in range(4):
#         njx = jx+dx[i]
#         njy = jy+dy[i]

#         if njx < 0 or njy <0 or njx >=n or njy >=m:
#             flag = True
#             ans.append([jx,jy])
            
            
#         else :
#             if arr[njx][njy] == 0 and not visited[njx][njy]:
#                 jh.append([cnt,njx,njy])
#                 cnt_arr[njx][njy] = c
#                 visited[njx][njy] = True
#     if flag: break
#     jh.sort()
    
            

# if flag: 
#     a,b = ans.pop()
#     print(cnt_arr[a][b]+1)
# else : print('IMPOSSIBLE')



# '''
# 1. 불이 번짐 
# 2. 지훈이 도망감 가능한 자리 스택에 다 넣기 이때 몇번째로 이동한건지 같이 넣어서 cnt_arr에 값 입력 후 탈출 시 출력
# 3. 만약 사방으로 막혀있으면 탈출 불가
# 3. 만약 가장자리이면 탈출
# '''


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

            else : 
                #if visited_f[nx][ny] > visited_j[nx][ny]:
                return visited_j[x][y]
                

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

                    
