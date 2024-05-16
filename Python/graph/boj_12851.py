# 숨바꼭질 gold 4
from collections import deque
import sys
input = sys.stdin.readline
Size = 100001

n,k = map(int,input().split())

que = deque([n])

cnt = [0] *Size
visited = [-1] *Size
visited[n] = 0
cnt[n] = 1

while que:
    x= que.popleft()

    for nx in [x-1,x+1,x*2]:
        if 0<=nx<Size :
            if visited[nx] == -1:
                visited[nx] = visited[x] + 1
                cnt[nx] = cnt[x]
                que.append(nx)
            
            elif visited[nx] == visited[x] + 1:
                cnt[nx] += cnt[x]
print(visited[k])
print(cnt[k])