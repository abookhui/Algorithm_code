#Holes silver 1

from collections import deque

d = [[0,1],[0,-1],[1,0],[-1,0]]

def dfs(x,y):
    visited[x][y] = 1

    for i in range(4):
        nx, ny = x + d[i][0], y + d[i][1]   

        if 0<=nx<r and 0<=ny<c:
            if not visited[nx][ny] and graph[nx][ny] == '.':
                visited[nx][ny] = 1
                dfs(nx,ny)

for _ in range(int(input())):
    
    graph = []
    r,c = map(int,input().split())

    visited = [[0] * c for s in range(r)]
    sections = 0
    spaces = 0
    for i in range(r):
        tmp = []
        line = input()
        for j in range(c):  
            if line[j] == '.': spaces +=1
            tmp.append(line[j])

        graph.append(tmp)
    
    for i in range(r):
        for j in range(c):
            if graph[i][j] == '.' and not visited[i][j]:
                dfs(i,j)    
                sections += 1
    
    ans = []
    if sections == 1: ans.append("section")
    else : ans.append("sections")

    if spaces == 1: ans.append('space')
    else : ans.append('spaces')

    print(sections,ans[0]+',',spaces,ans[1])


