# Minion Walk gold 5
# 해결 >> 좌측 상단이 X일 경우 

from collections import deque

d = [[0,1],[0,-1],[1,0],[-1,0]]

tc = int(input())

for test_case in range(tc):

    graph = []
    h,w = map(int,input().split())
    visited = [[0]*w for _ in range(h)]

    for i in range(h):
        tmp = []
        line = input()
        for j in range(w):
            tmp.append(line[j])

        graph.append(tmp)

    que = deque()
    if graph[0][0] == 'O': que.append([0,0])

    while que:
        x,y = que.popleft()
        visited[x][y] = 1

        for i in range(4):
            nx, ny = x + d[i][0], y+d[i][1] 

            if 0<=nx<h and 0<=ny<w:
                if graph[nx][ny] == 'O' and not visited[nx][ny]:
                    que.append([nx,ny])
                    visited[nx][ny] = 1
    
    ans = []
    for i in range(h):
        tmp = []
        for j in range(w):
            if graph[i][j] == 'O':
                if visited[i][j]: tmp.append('M')
                else : tmp.append(" ")
            else : tmp.append('X')
        ans.append(tmp)

    print("Case:",test_case+1)

    print('+---'* w+'+')
    for i in range(h):
        for j in range(w):
            print('|',ans[i][j],'',end="")
        print('|')
        print('+---'* w+'+')
    

    if visited[h-1][w-1] and graph[0][0]=='O' :  print("Minions can cross the room")
    else : print("Minions cannot cross the room")

    