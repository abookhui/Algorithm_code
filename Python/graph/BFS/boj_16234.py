# 인구 이동 gold 4

# 시간초과
# bfs 에서 ans에 i,j가 넣어지지 않아서 계속 뱅뱅도는 루프가 생김 
# 다시 ans에 본인 i,j먼저 넣어주니 값 cnt+1로 나옴 

# 방문하지 않았고 인구수 차이가 범위 안에 있다면 그 좌표를 ans에 넣어주어서 함수끝나고 반환
# 조건대로 인구수 변화시키고 다시 방문안한데 찾음
# 한 바퀴 돌면 cnt++ 다시 방문초기화 시키고 또 조건 만족하는 좌표있는지 확인 .. 반복
# 만약 이제 다 bfs 반환 덱이 1이면(본인만 포함하면) 끝냄 >> flag로 표현
  

from collections import deque
import sys
input = sys.stdin.readline

n,l,r = map(int,input().split())    

arr = [list(map(int,input().split())) for _ in range(n)]

d = [[0,1],[0,-1],[1,0],[-1,0]]
def bfs(a,b):
    
    que = deque([[a,b]])
    ans = deque([[a,b]])

    while que:
        x,y = que.popleft()

        for i in range(4):
            nx,ny = x+d[i][0], y+d[i][1]

            if 0<=nx<n and 0<=ny<n:
                if l<=abs(arr[nx][ny]-arr[x][y])<=r and not visited[nx][ny]:
                    visited[nx][ny] = 1
                    que.append([nx,ny])
                    ans.append([nx,ny])
    if not len(ans) :
        ans.append([a,b])
    return ans

cnt = 0
flag = True
while flag:
    visited = [[0] * n for _ in range(n)]
    flag = False
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                visited[i][j] = 1
                country = bfs(i,j)
                
                if len(country) > 1:
                    flag = True
                    man = sum(arr[x][y] for x, y in country) // len(country)
                    
                    for x, y in country:
                        arr[x][y] = man
    cnt += 1
print(cnt-1)
            
