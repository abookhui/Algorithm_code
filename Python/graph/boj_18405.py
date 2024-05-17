# # 경쟁적 전염 gold 5
# from collections import deque
# import sys
# input = sys.stdin.readline

# n,k = map(int,input().split())
# graph = [list(map(int,input().split())) for _ in range(n)]
# s,a,b = map(int,input().split())

# lab = deque()
# visited = [[0]*(n) for _ in range(n)]
# max_num =0
# min_num =1000
# for i in range(n):
#     for j in range(n):
#         num = graph[i][j]
#         if num :
#             max_num = max(num,max_num)
#             min_num = min(num,min_num)
#             lab.append([num,i,j,0])

# lab = deque(sorted(lab)) # sort해줘서 작은 값 먼저 bfs 돌게 해주기

# d = [[1,0],[-1,0],[0,1],[0,-1]]

# pri_num = 0
# cnt = 0

# # lab_len = len(lab)
# # if lab_len ==0 :
# #     print(graph[a-1][b-1])
# #     exit()

# # while lab:
# #     num,x,y,seq= lab.popleft()
# #     if max_num == min_num :
# #         if seq == s:
# #             print(graph[a-1][b-1])
# #             exit()
# #     elif pri_num == max_num and num == min_num: # 이전 num이 가장 큰 num에서 가장 작은num으로 바뀜 == 한바퀴 돌았다
# #         cnt+=1
# #         pri_num = num
# #     else : pri_num = num

# #     if cnt == s  :
# #         print(graph[a-1][b-1])
# #         exit()
# #     for i in range(4):
# #         nx,ny = x+d[i][0], y+d[i][1]    

# #         if 0<=nx<n and 0<=ny<n:
# #             if not visited[nx][ny] and graph[nx][ny]==0:
# #                 visited[nx][ny] = visited[x][y] + 1
# #                 graph[nx][ny] = num
# #                 lab.append([num,nx,ny,seq+1])


from collections import deque
import sys
input = sys.stdin.readline

n,k = map(int,input().split())
graph = [list(map(int,input().split())) for _ in range(n)]
s,a,b = map(int,input().split())

# graph를 정렬해 주어 작은 바이러스 먼저 bfs를 돌린다.
# 각 seq를 넣어주어 몇번째 몇초 뒤 인지 확인
# s와 seq가 같다면 graph 출력

lab = deque()
visited = [[0]*(n) for _ in range(n)]
max_num =0
min_num =1000
for i in range(n):
    for j in range(n):
        if graph[i][j]:
            max_num = max(graph[i][j],max_num)
            min_num = min(graph[i][j],min_num)
            lab.append([graph[i][j],i,j,0])

lab = deque(sorted(lab)) # sort해줘서 작은 값 먼저 bfs 돌게 해주기



if len(lab) == 0:
    print(graph[a-1][b-1])
    exit()

d = [[1,0],[-1,0],[0,1],[0,-1]]
while lab:
    num,x,y,seq = lab.popleft()

    if seq == s or seq<s and visited[a-1][b-1]:
        print(graph[a-1][b-1])
        exit()
    
    for i in range(4):
        nx,ny = x+d[i][0],y+d[i][1]

        if 0<=nx<n and 0<=ny<n:
            if not visited[nx][ny]:
                lab.append([num,nx,ny,seq+1])
                visited[nx][ny] = visited[x][y] + 1
                graph[nx][ny] = num




