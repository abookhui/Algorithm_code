# # 양 3184 - silver 1
# #  '.' (점)은 빈 필드, '#'는 울타리, 'o'는 양, 'v'는 늑대

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

r,c = map(int,input().split())

graph = [list(map(str,input().rstrip())) for _ in range(r)]

wof = []
shp = 0
for i in range(r):
    for j in range(c):
        if graph[i][j] == 'v':
            wof.append([i,j])
        elif graph[i][j] == 'o':
            shp += 1

shp_cnt = 0
wof_cnt = 0

# v 인 좌표에서 각 영역에 v와 o가 몇개있는지 확인 
# 이미 방문한 곳은 .으로 바꾸기 

visited = [[0]*c for _ in range(r)]
def dfs(x,y):
    global ans_w,ans_s
    
    if visited[x][y]: return
    if graph[x][y] == 'v' : ans_w += 1
    visited[x][y] = 1
    for i in [[-1,0],[0,1],[1,0],[0,-1]] :
        nx,ny = x+i[0],y+i[1]

        if 0<=nx<r and 0<=ny<c and not visited[nx][ny]:
            if graph[nx][ny] == '#': continue

            elif graph[nx][ny] == 'v':
                graph[nx][ny] ='.'
                ans_w += 1
            elif graph[nx][ny] == 'o':
                graph[nx][ny] ='.'
                ans_s += 1
            dfs(nx,ny)
     
while wof:
    ans_w = ans_s = 0
    a,b = wof.pop()
    dfs(a,b)
    graph[a][b] = '.'
    if ans_w < ans_s : shp_cnt += ans_s
    else: 
        wof_cnt += ans_w
        shp -= ans_s

print(shp_cnt+(shp-shp_cnt),wof_cnt)

# import sys
# from collections import deque
# input = sys.stdin.readline

# r,c = map(int,input().split())
# graph = [list(map(str,input().rstrip())) for _ in range(r)]

# wof = []
# shp = 0
# for i in range(r):
#     for j in range(c):
#         if graph[i][j] == 'v':
#             wof.append([i,j])
#         elif graph[i][j] == 'o':
#             shp +=1
# visited = [[0]*c for _ in range(r)]

# ans_w = ans_s = 0

# def bfs(a,b):
#     global ans_w, ans_s,shp
#     cnt_w=cnt_s=0
#     que = deque([[a,b]])
#     if graph[a][b] == 'v' : cnt_w += 1
#     visited[a][b] = 1
#     while que:
#         x,y = que.popleft()

#         for d in [[-1,0],[0,1],[1,0],[0,-1]]:
#             nx,ny = x+d[0],y+d[1]

#             if 0<=nx<r and 0<=ny<c and not visited[nx][ny]:
#                 if graph[nx][ny] == '#': continue
#                 elif graph[nx][ny] == 'v': cnt_w += 1
#                 elif graph[nx][ny] == 'o': cnt_s += 1
#                 graph[nx][ny] ='.'
#                 visited[nx][ny] = 1
#                 que.append([nx,ny])

#     if cnt_w < cnt_s : ans_s += cnt_s
#     else : 
#         ans_w += cnt_w
#         shp -= cnt_s

# while wof:
#     a,b = wof.pop()
#     if not visited[a][b]:
#         bfs(a,b)
#         graph[a][b] = '.'
# print(ans_s+(shp-ans_s),ans_w)