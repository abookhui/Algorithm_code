# N-Queen 9663 - gold 4

import sys
input = sys.stdin.readline

n = int(input())
upward = [0] * (2*n)
down = [0] * (2 * n)
line = [0]*n
cnt = 0

#arr = [[0]*n for _ in range(n)]
# for i in range(n): 우하향
#     for j in range(n):
#         arr[i][j] = (n-1)-i +j
# print(arr)
# arr = [[0]*n for _ in range(n)]
# for i in range(n): 우상향
#     for j in range(n):
#         arr[i][j] = i+j
#print(arr)

def sol(x,y):
    # 가능한 행을 찾으면 다음 열로 이동
    # 안되면 뒤로 빽

    if not (0<=x<n and 0<=y<n) : return 

    if line[x] or upward[x+y] or down[(n-1)-x+y]: sol(x+1,y)
        
    else : # 만약 가능하면 넣기
        line[x] =  upward[x+y] = down[(n-1)-x+y] = 1
        if y+1>=n :
            global cnt
            cnt+=1
        else : sol(0,y+1) # 다음 열로 이동
        line[x] =  upward[x+y] = down[(n-1)-x+y] = 0
        sol(x+1,y)

sol(0,0)
print(cnt)         


