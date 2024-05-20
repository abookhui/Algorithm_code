# # 알파벳 gold 4

# from collections import deque
# dx = [1,-1,0,0]
# dy = [0,0,1,-1]
# #   2
# # 4 0 3
# #   1



# r, c = map(int,input().split())


# alph = [False]*26 # 알파벳 방문 조사
# visited = [[False]*c for _ in range(r)] # arr 방문


# arr = []
# for i in range(r):
#     tmp = []
#     line = input()
#     for j in range(c):
#         tmp.append(ord(line[j])-65)
#     arr.append(tmp)

# stack= [[0,0]]
# cnt = 0

# def Counting(x,y):
#     ans = 0
#     for i in range(4):
#         nx,ny = x+dx[i],y+dy[i]
#         if 0<=nx<r and 0<=ny<c:
#             if not visited[nx][ny] and not alph[arr[nx][ny]] and arr[x][y]!=arr[nx][ny]:
#                 ans += 1
#     return ans
    

# while stack:
#     x,y = stack.pop()
#     if not alph[arr[x][y]]: cnt+=1
#     else : continue

#     visited[x][y] = alph[arr[x][y]] = True

#     tmp = []
#     for i in range(4):
#         nx,ny = x+dx[i],y+dy[i]

#         if 0<=nx<r and 0<=ny<c:
#             if not visited[nx][ny] and not alph[arr[nx][ny]]:
#                 #visited[nx][ny] = True
#                 stack.append([nx,ny])
#                 #tmp.append([Counting(nx,ny),nx,ny])
#     #tmp.sort()

#     # while tmp:
#     #     num,a,b = tmp.pop(0)
#     #     stack.append([a,b])
    
# print(cnt)

# # 0 0 에서 상하좌우를 확인
# # 만약 방문하지 않았고 새로운 알파벳이면 스택에 넣기
# # 스택에 있는 노드 중 방문가능한 수 가 많은(본인과 같은 알파벳 제외) 노드 먼저 방문하기

# 2 4
# CALB
# ADCB 반례 ans: 4 , output 5 
 # CALB 갔다가 안들려야하는 D를  stack에 다 넣어서 count 해버림 

# 알파벳 gold 4
import sys
sys.setrecursionlimit(10**6)

dx = [1,-1,0,0]
dy = [0,0,1,-1]
r, c = map(int,input().split())

ans = 0 #UnboundLocalError

def dfs(x,y,cnt):
    global ans
    ans = max(ans,cnt)

    for i in range(4):
        nx,ny = x+dx[i],y+dy[i]

        if 0<=nx<r and 0<=ny<c:
            if not alph[arr[nx][ny]]:
                alph[arr[nx][ny]] = True
                dfs(nx,ny,cnt+1)
                alph[arr[nx][ny]] = False

alph = [False]*26 # 알파벳 

arr = []
for i in range(r):
    tmp = []
    line = input()
    for j in range(c):
        tmp.append(ord(line[j])-65)
    arr.append(tmp)

alph[arr[0][0]] = True
dfs(0,0,1)
print(ans)
