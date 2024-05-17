# 숨바꼭질4 gold 4
from collections import deque
import sys
input = sys.stdin.readline
Size = 100001

n,k = map(int,input().split())

visited = [0] *Size

que = deque([[n , [n]]])

while que:
   
    x, line = que.popleft()
    if x == k :
        print(visited[k])
        print(' '.join(map(str,line)))
        break
    
    for nx in [x-1,x+1,x*2]:
        tmp = line[:]

        if 0<=nx<Size:
            if not visited[nx]:
                visited[nx] = visited[x] + 1
                tmp.append(nx)
                que.append([nx,tmp])
        