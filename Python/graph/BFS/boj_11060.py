# 점프 점프 silver 2
# n==1 일 때를 조건에 넣지 않아 99%에서 틀렸습니다. 가 나왔다.

from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int,input().split()))

que = deque([0])

visited = [0] * n
while que:
    x = que.popleft()

    for i in range(1,arr[x]+1):
        nx = x + i

        if 0<=nx<n and not visited[nx]:
            visited[nx] = visited[x] + 1
            que.append(nx)
    
if visited[n-1] or n==1: print(visited[n-1])
else : print(-1)