import sys
input = sys.stdin.readline

arr = [list(map(str,input().split())) for _ in range(5)]

ans = set()

def dfs(x,y,num):
    if len(num) == 6: 
        ans.add(num)
        return

    for nx,ny in [[x,y+1],[x,y-1],[x+1,y],[x-1,y]]:
        if 0<=nx<5 and 0<=ny<5:
            dfs(nx,ny,num+arr[nx][ny])


for i in range(5):
    for j in range(5):
        dfs(i,j,arr[i][j])
print(len(ans))