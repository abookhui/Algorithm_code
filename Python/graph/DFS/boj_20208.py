# 진우의 민트초코우유 - gold 5

import sys
from collections import defaultdict
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

n, m, h = map(int, input().split())    
graph = [list(map(int, input().split())) for _ in range(n)]

mint = []

for i in range(n):
    for j in range(n):
        if graph[i][j] == 1:
            hi, hj = i, j
        elif graph[i][j] == 2:
            mint.append([i,j])

num = len(mint)

visited = [0] * num
ans = 0

def dfs(x,y,hp,cnt): # 초코촠만 dfs돌기 
    global ans

    if abs(x-hi) + abs(y-hj) <= hp and cnt>0:
        ans = max(ans,cnt)

    for i in range(num):
        if not visited[i]:
            tmp = abs(x-mint[i][0]) + abs(y-mint[i][1])
            if tmp <= hp:
                visited[i] = 1
                dfs(mint[i][0],mint[i][1],hp-tmp+h,cnt+1)
                visited[i] = 0
    
dfs(hi,hj,m,0)  
print(ans)