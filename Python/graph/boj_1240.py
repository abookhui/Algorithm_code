# 노드사이의 거리 gold 5
# dict를 이용해 노드와 연결된 노드를 chk하고 
# 따로 dist 리스트를 만들어 que에 같이 넣어줘 확인

import sys
from collections import deque
input = sys.stdin.readline

n,m = map(int,input().split())

arr = {}
dist = [[0]*(n+1) for _ in range(n+1)]
for _ in range(n-1):
    a,b,d = map(int,input().split())
    
    if a in arr: arr[a].append(b)
    else : arr[a] = [b]

    if b in arr: arr[b].append(a)
    else : arr[b] = [a]
    dist[a][b] = d
    dist[b][a] = d
        
for _ in range(m):
    visited = [0] * (n+1)
    a,b = map(int,input().split())

    que = deque([[a,0]])
    
    while que:
        x,cnt = que.popleft()

        if b in arr[x]: 
            print(cnt + dist[x][b])
            break
        
        for i in arr[x]:
            if not visited[i]:
                visited[i] = 1
                que.append([i,cnt+dist[x][i]])  