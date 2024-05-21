# 농장 관리

n,m = map(int,input().split())

arr = []

dx = [1,-1,0,0,-1,-1,1,1]
dy = [0,0,1,-1,-1,1,1,-1]

def Mountain(x,y): 
    stack = []
    stack.append([x,y])
    chk =True
    while stack: 
        a,b = stack.pop()

        for i in range(8):
            nx = a + dx[i]
            ny = b + dy[i]

            if nx >= 0 and ny >= 0 and nx < n and ny < m:
                if not visited[nx][ny] and arr[x][y] == arr[nx][ny]: # 같으면 스택에 넣고 확인
                    stack.append([nx,ny])
                    visited[nx][ny] = True

                elif arr[x][y] < arr[nx][ny]: # 높이가 더 크면 봉우리 아님
                    chk =  False
                
    if chk : return True
    else : return False

for i in range(n):
    arr.append(list(map(int,input().split())))
cnt =0
visited = [[False] *m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if not visited[i][j] and  Mountain(i,j) and not arr[i][j]==0: 
            cnt+=1  

print(cnt)

# 반례
# 2 2
# 0 0
# 0 0
# 다 0 인데 1 나옴 0일때 제외하니 됨
