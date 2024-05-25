# 나무 탈출 15900 - silver 1

# leafnode 찾기
# 자신과 연결된 노드를 모두 이어주면 각 연결된 노드들이 표시되는데
# 여기서 연결된 노드가 1개라면 부모노드만 존재한다는 의미 즉 리프노드
# 단 루트는 제외
import sys
from collections import defaultdict
sys.setrecursionlimit(500000)
n = int(sys.stdin.readline())
tree = defaultdict(list)
visit = [0]*(n+1)
ans = 0
for _ in range(n-1):
    a,b = map(int,sys.stdin.readline().split())
    tree[a].append(b)
    tree[b].append(a)

def dep(N):
    visit[N] = 1
    for i in tree[N]:
        if visit[i] == 0:
            depth[i] = depth[N] + 1
            dep(i)

dep(1)
for i in range(2,n+1):
    if len(tree[i]) == 1:  
        ans += depth[i]

if ans % 2 == 0: print("No")
else: print("Yes")