#숨바꼭질 gold 5
import sys
input = sys.stdin.readline 
from collections import deque
Size = 100001

n,k = map(int,input().split())
visited = [False]*Size
dist = [-1] *Size

que = deque([n])
dist[n] = 0
visited[n] = True
while que:
    x = que.popleft()
    if n==k: 
        print(0) 
        exit()
    nx = x*2
    if 0<=nx<Size and not visited[nx]:
        visited[nx] = True
        dist[nx] = dist[x]
        que.appendleft(nx)
    for nx in [x-1,x+1]: # -, + 누구먼저하느냐 차이의 오류 4 6 1이냐 2냐 나옴
        if 0<=nx<Size and not visited[nx]:
            visited[nx] = True
            dist[nx] = dist[x] +1
            que.append(nx)

print(dist[k])