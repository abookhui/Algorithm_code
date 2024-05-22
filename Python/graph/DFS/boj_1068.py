# 트리 1068 - gold 5

from collections import defaultdict
import sys
input = sys.stdin.readline

tree = defaultdict(list)
n = int(input())
arr = list(map(int,input().split()))
m = int(input()) 
if arr[m] == -1: 
    print(0) 
    exit()

for i in range(n):
    if arr[i] == -1:
        root = i
    else: 
        tree[arr[i]].append(i)
        tree[i].append(arr[i])

tree[arr[m]].remove(m)
tree[m].remove(arr[m])

def RemoveNode(node):
    if len(tree[node]) <=0 : 
        del tree[node]
        return 
    while tree[node]:
        RemoveNode(tree[node].pop(0))

    if len(tree[node])==0: del tree[node]

RemoveNode(m)
ans =0
for node in tree:
    if len(tree[node]) == 1 and node != root:
        ans+=1
print(ans if len(tree)!= 1 else 1)