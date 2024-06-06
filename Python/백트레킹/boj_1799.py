# 비숍 1799 - gold 1

import sys
input = sys.stdin.readline

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]

# n = 5
#    
#    00 
#    10 01
#    20 11 02
#    30 21 12 03
#    40 31 22 13 04
#    41 32 23 04
#    42 33 24
#    43 34 
#    44

#    40
#    30 41
#    20 31 42
#    10 21 32 43
#    00 11 22 33 44
#    01 12 23 34
#    02 13 24
#    03 14
#    04

# n-x+y
#        00               0
#      10  01             1
#    20  11  02           2
#  30  21  12  03         3
#40  31  22  13  04       4
#  41  32  23  14         5
#    42  33  24           6
#      43  34             7
#        44               8
#0 1 2 3 4 5 6 7 8

line = [0] * (2*n) # x+y
down = [0] *  (2*n)
ans1 = ans2 = 0

def sol(x,y,dep,cnt,chk):
    global ans1,ans2
    if chk : ans1 = max(ans1,cnt)
    else : ans2 = max(ans2,cnt)
    
    if x+y > 2*(n-1): return
    if not (0<=x<n and 0<=y<n): return
    
    if line[x+y] == 0 and down[n-1-x+y]==0 and arr[x][y]==1: # 가능한 위치
        line[x+y] = down[n-1-x+y] = 1

        # 이 줄은 이미 먹었으니 다음줄로 넘어감
        if dep+2 >= n-1: sol(n-1,dep+2-(n-1),dep+2,cnt+1,chk) # 반 이상 깊이면 x= n-1  
        else : sol(dep+2,0,dep+2,cnt+1,chk) # 이하면 x=dep+1, y=0
        line[x+y] = down[n-1-x+y] = 0

    # 가능한곳 없고 다음으로 넘어가기
    elif dep ==0 : sol(dep+2,0,dep+2,cnt,chk)
    elif dep+2 < n-1 and dep == y : # 반 이하
        sol(dep+2,0,dep+2,cnt,chk)
    elif dep+2 >= n-1 and (y == n-1 or y==dep): # 반 이상부터는 맨끝 라인부터
        sol(n-1,dep+2-(n-1),dep+2,cnt,chk)
    
    sol(x-1,y+1,dep,cnt,chk) # 옆으로 이동


sol(0,0,0,0,1)
if n>1 : sol(1,0,1,0,0) # 반나눠서 시간줄이기
print(ans1+ans2)

