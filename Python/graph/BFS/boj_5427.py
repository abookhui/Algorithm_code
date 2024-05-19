# 불 gold 4 

# 불이 각 1초마다 퍼짐 이 때 몇 초때 퍼졌는 지 방문배열에 count
# 상근이가 1초마다 갈 수 있는 길에 몇 초때에 갔는지 방문배열에 count 
# 이때 불 상근 각각 배열 따로 
# 그리고 상근이가 범위 밖으로 갔을때 불보다 빨리 갔는지 또는 불이 안왔으면 탈출
# 불이 더 빨리 왔던 길이면 실패

from collections import deque

d = [[1,0],[-1,0],[0,1],[0,-1]]

tc = int(input())

while tc: 
    w,h = map(int,input().split())

    arr = []
    visited_f = [[0]*w for _ in range(h)]
    visited_s = [[0]*w for _ in range(h)]
    fire = deque()
    sg = deque()


    def Change(key):
        ans = {'.':0,'@':0, '#':2, '*':3}.get(key) # get 두번째 인자에 default 시 값 넣을 수 있음
        return ans
    def bfs():
        while fire:
            x,y = fire.popleft()

            for i in range(4):
                nx,ny = x+d[i][0],y+d[i][1]

                if 0<=nx<h and 0<=ny<w:
                    if not visited_f[nx][ny] and arr[nx][ny]==0:
                        fire.append([nx,ny])
                        visited_f[nx][ny] +=visited_f[x][y] + 1
        while sg:
            x,y = sg.popleft()

            for i in range(4):
                nx,ny = x+d[i][0],y+d[i][1]

                if 0<=nx<h and 0<=ny<w:
                    if not visited_s[nx][ny] and arr[nx][ny]==0:
                        if visited_f[nx][ny] > visited_s[nx][ny] + 1 or visited_f[nx][ny]==0:
                            visited_s[nx][ny] += visited_s[x][y] +1
                            sg.append([nx,ny])
                else :
                    if visited_f[x][y] > visited_s[x][y] or visited_f[x][y] == 0:
                        return visited_s[x][y]
        return 'IMPOSSIBLE' 
    for i in range(h):
        tmp = []
        line = input()
        for j in range(w):
            num = Change(line[j])
            if line[j] == '@':
                sg.append([i,j])
                visited_s[i][j] = 1
            elif line[j] == '*':
                fire.append([i,j])
                visited_f[i][j] = 1
            tmp.append(num)
        arr.append(tmp)
    print(bfs())
    tc-=1
   
