# 전단지 돌리기 19542 - gold 3

import sys
from collections import defaultdict
sys.setrecursionlimit(100001)
input = sys.stdin.readline

tree = defaultdict(list)
n,s,d = map(int,input().split())

for _ in range(n-1):
    a,b = map(int,input().split())  
    tree[a].append(b)
    tree[b].append(a)


# 노드 본인의 뒤에 몇개가 있는지 확인 (본인 포함)
# 1 2
# 2 3
# 2 4
# 3 5
# 5 6
# 그러면 예시에서 4와 6은 1개로 d와 같거나 작기 때문에 트리에서 없애버리기 
# dep 에서 d보다 크거나 같은 수 *2 출력

dep = [0] *(n+1)

# 리프노드부터 몇개의 자식을 가지는지 cnt
def dfs(node,par): # 본인 뒤에 몇개 있는지 확인
    if node !=s and len(tree[node]) == 1: 
        dep[node] = 0
        return 0

    for nn in tree[node]:
        if nn == par : continue
        dep[node] = max(dep[node],dfs(nn,node)+1)

    return dep[node]

dfs(s,0)

for i in range(1,n+1): # 연결 끊어주기 
    dd = dep[i]
    if i != s and  dd < d:
        for j in tree[i]:
            tree[j].remove(i)
        del tree[i]

ans = 0
for i in range(1,n+1):
    if i!=s and dep[i]>=d :
        ans+=1
print(ans*2)


   