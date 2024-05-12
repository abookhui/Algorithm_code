


t = int(input())

for _ in range(t):

    ans = 0
    def dfs(x,num):
        visit[x] = 1  
        nx = x+1
        global ans
        ans = max(nx,ans)
        if 0<=nx<len(arr):
            if not visit[nx] and arr[nx] == num:
                visit[nx] = 1
                dfs(nx,num)
        return ans
    arr = []
    
    line = input()
    visit = [0]*len(line)

    for i in range(len(line)):
        arr.append(ord(line[i])-48)
    
    cnt=0
    flag = 1

    for i in range(len(arr)):
        if not visit[i]:
            if arr[i] == 0:
                if i+1 < len(arr) and arr[i+1] == 1 and flag and not visit[i+1]:
                    dfs(i,1)
                    flag = 0
                else :
                    next = dfs(i,0)
                    if next < len(arr) and arr[next] == 1 and flag and not visit[next]:
                        dfs(next,1)
                        flag = 0
                visit[i] = 1
                cnt+=1
            elif arr[i] == 1:        
                dfs(i,1)
                visit[i] = 1
                cnt+=1
    if arr[0] == 0 and arr[len(arr)-1] ==1:
        if cnt ==2: print(1)
        else : print(cnt)
    else : print(cnt)