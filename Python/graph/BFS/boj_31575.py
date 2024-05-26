import sys  
from collections import defaultdict
from collections import deque
input = sys.stdin.readline

n,m = map(int,input().split())

arr = [list(map(int,input().split())) for _ in range(m)]
visited = [[0]*n for _ in range(m)]
    
def bfs(a,b):
    que = deque([[a,b]])
    visited[a][b] = 1
    flag = False
    while que:
        x,y = que.popleft()
        if x == m-1 and y == n-1:
            flag = True
            break 
        for nx,ny in [[x+1,y],[x,y+1]]:
            if 0<=nx<m and 0<=ny<n :
                if arr[nx][ny] == 1 and not visited[nx][ny]:
                    que.append([nx,ny])
                    visited[nx][ny] = 1
    return flag

ans = bfs(0,0)  
if ans : print('Yes')
else : print('No')


    
