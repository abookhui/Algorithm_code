# 완전 범죄 silver 1
# 시간 초과
from collections import deque

n,s,d,f,b,k = map(int,input().split())

if k>0 : k_list = list(map(int,input().split()))

for i in range(k):
    k_list[i] -=1

visited = [0]* n

que = deque()
que.append(s-1)
visited[s-1] = 1 

while que:
    x = que.popleft()

    fx, bx = x+f,x-b

    if 0<=fx<n:
        if not visited[fx]:
            if k == 0:
                que.append(fx)
                visited[fx] = visited[x] + 1
            else :
                if not fx in k_list:
                    que.append(fx)
                    visited[fx] = visited[x] + 1
    if 0<=bx<n:

        if not visited[bx] : 
            if k == 0:
                que.append(bx)
                visited[bx] = visited[x] + 1
            else : 
                if not bx in k_list:       
                    que.append(bx)
                    visited[bx] = visited[x] + 1

if visited[d-1]: print(visited[d-1]-1)
else : print('BUG FOUND')