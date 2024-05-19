# 프로그래머스 level 2

from collections import deque
import sys
input = sys.stdin.readline


def solution(maps):
    d = [[1,0],[-1,0],[0,1],[0,-1]]
    n,m = len(maps),len(maps[0])
    visited = [[0]*m for _ in range(n)]
    visited[0][0] = 1
    que = deque([[0,0,1]])
    answer = 0
    while que:
        x,y,cnt = que.popleft()
        if x == n-1 and y == m-1:
            answer = cnt
            break
        
        for i in range(4):
            nx,ny = x+d[i][0],y+d[i][1]
            
            if 0<=nx<n and 0<=ny<m:
                if not visited[nx][ny] and maps[nx][ny] == 0:
                    visited[nx][ny] = 1
                    que.append([nx,ny,cnt+1])
                    
        
    if not answer: answer = -1
    
    return answer

# arr = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]
# print(solution(arr))