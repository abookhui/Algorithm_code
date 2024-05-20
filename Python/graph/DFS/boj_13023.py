# ABCDE 13023 - gold 5

import sys
from collections import defaultdict
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n,m = map(int,input().split())

friends = defaultdict(list)
visited = [0]*n 

for i in range(m):
    a,b = map(int,input().split())
    friends[a].append(b)
    friends[b].append(a)


ans = 0
def dfs(x,cnt):
    global ans
    if cnt == 4:
        ans = 1
        return
    
    visited[x] = 1
    for i in friends[x]:
        if not visited[i]:
            dfs(i,cnt+1)

    visited[x] = 0

for i in range(n):
    dfs(i,0)
    if ans : 
        break
print(ans)