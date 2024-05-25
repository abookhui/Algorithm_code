# 구슬 2617 - gold 4

import sys  
from collections import defaultdict
input = sys.stdin.readline

heavy = defaultdict(list)
light = defaultdict(list)

n,m = map(int,input().split())

for _ in range(m):
    a,b = map(int,input().split()) # a > b
    heavy[b].append(a)
    light[a].append(b)

# print(heavy)
# print(light)

def dfs(x,lit):
    result = 0

    for nn in lit[x]:
        if not visited[nn]:
            visited[nn] = 1
            result += 1
            result += dfs(nn,lit)
    return result

mid = (n+1)/2  
cnt =0
for i in range(1,n+1):
    visited = [0] *(n+1)
    if dfs(i,heavy) >= mid:
        cnt+=1
    if dfs(i,light) >= mid:
        cnt+=1
    
print(cnt)
