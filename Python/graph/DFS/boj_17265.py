# 나의 인생에는 수학과 함께 17265 - gold 5

import sys
from collections import defaultdict
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n = int(input())
visited = [[0]*n for _ in range(n)]
graph = [list(map(str,input().split())) for _ in range(n)]

for i in range(n):
    for j in range(n):
        graph[i][j] = {'+': 11,'-':12,'*':13}.get(graph[i][j]) or int(graph[i][j])


max_ans = -5**6 # max_ans =0으로 하면 안됨
min_ans = 5**6

def dfs(x,y,op,num):
    global max_ans, min_ans
    visited[x][y] = 1

    if x == n-1 and y == n-1:
        max_ans = max(max_ans,num)
        min_ans = min(min_ans,num)
        visited[x][y] = 0
        return 
    
    for i in [[0,1],[1,0]]:
        nx,ny = x+i[0], y+i[1]

        if 0<=nx<n and 0<=ny<n and not visited[nx][ny] :
            if graph[nx][ny] <= 5: # 숫자
                sum = {1 : num+graph[nx][ny],
                       2 : num-graph[nx][ny],
                       3 : num * graph[nx][ny],
                       0 : num }.get(op)      
                dfs(nx,ny,0,sum)
           
            else : #연산자
                dfs(nx,ny,graph[nx][ny]%10,num)
    visited[x][y] = 0

dfs(0,0,0,graph[0][0])
print(max_ans,min_ans)
    