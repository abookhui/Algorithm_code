# 숨바꼭질 silver 1

import sys
input = sys.stdin.readline 
from collections import deque
Size = 100001

n,k = map(int,input().split())
visited = [0]*Size

que = deque()
que.append(n)
if n==k: print(0)

else :
    while que:
        x = que.popleft()

        seek = [x+1,x-1,x*2]
        flag = False
        while seek:
            nx = seek.pop()
            if nx == k : flag = True
            if 0<=nx<Size and not visited[nx] and nx!=x:
                visited[nx] = visited[x] + 1
                que.append(nx)
        if flag:
            print(visited[k])
            break
        
