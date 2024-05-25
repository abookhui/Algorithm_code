# 트리의 높이와 너비 2250 - gold 2

import sys
from collections import defaultdict
input = sys.stdin.readline

n = int(input())    

tree = [[-1] *2 for _ in range(n+1)]
col = [0] * (n+1)
row = [0] * (n+1)

for _ in range(n):
    par,left,right = map(int,input().split())
    tree[par][0] = left
    tree[par][1] = right

visited = [0] * (n+1)

def sol_root(node,cnt):
    global root_cnt
    root_cnt = max(cnt,root_cnt)
    if visited[node] or tree[node][0] == -1 and tree[node][1] == -1 : return

    visited[node] = 1

    for i in range(2):
        nn = tree[node][i]
        if nn != -1 and visited[nn]==0 :
            sol_root(nn,cnt+1)
            
    visited[node] = 0

root_node =root_cmp =0 
for i in range(1,n+1): # 루트노드 구하기
    root_cnt = 0
    sol_root(i,0)
    if root_cmp < root_cnt:
        root_cmp = root_cnt
        root_node = i
    
order_cnt=1
def inorder(node): #중위 순회
    global order_cnt

    visited[node] = 1
    le = tree[node][0]
    ri = tree[node][1]

    if le!=-1 and not visited[le] : inorder(le)

    col[node] = order_cnt
    order_cnt+=1 

    if ri!=-1 and not visited[ri]: inorder(ri)

def dep(node,lev): # 레벨 구하기
    le = tree[node][0]
    ri = tree[node][1]

    visited[node] = 2 # 방문배열 공유

    row[node] = lev
    lev +=1
    if le!=-1 and visited[le] <= 1 : dep(le,lev)
    if ri!=-1 and visited[ri] <= 1 : dep(ri,lev)


inorder(root_node)
dep(root_node,1)

arr = defaultdict(list)
ans = 0
ans_lev = 0

for i in range(1,n+1): # 같은 레벨의 열 넣기
    arr[row[i]].append(col[i])

for i in range(1,n+1):
    if len(arr[i]) > 1:
        cmp = max(arr[i]) - min(arr[i]) + 1
        if cmp>ans:
            ans_lev = i
            ans = cmp

if ans_lev ==0 and ans ==0 :
    print(1,1)
else : print(ans_lev,ans)
