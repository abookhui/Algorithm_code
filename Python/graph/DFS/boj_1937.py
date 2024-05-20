# 욕심쟁이 판다 1937 - gold 3

import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n = int(input())
graph = [list(map(int,input().split())) for _ in range(n)]
visited = [[0]*n for _ in range(n)]
move = [[1]*n for _ in range(n)]

# 각 좌표마다 dfs를 돌려 가능한 칸수를 move에 저장해 최댓값 출력>> 그냥하면 시간 초과가 남
#  move[x][y] = max(dfs(nx,ny) + 1,move[x][y]) 이미 방문한 곳은 추가로 돌리는게 아니라 해당 값 return 

def dfs(x,y):
    if visited[x][y]:
        return move[x][y]
    visited[x][y] = 1

    for d in [[0,1],[0,-1],[1,0],[-1,0]]:
        nx,ny = x+d[0],y+d[1]
        if 0<=nx<n and 0<=ny<n and graph[nx][ny] > graph[x][y]:
            move[x][y] = max(dfs(nx,ny) + 1,move[x][y])

    return move[x][y]

for i in range(n):
    for j in range(n):
        # if not visited[i][j]:
        dfs(i,j)

result =0
for i in range(n):
    result = max(result,max(move[i]))
print(result)
#print(max(map(max,move)))