# A → B silver 2
# visited를 만들면 10**9까지 범위가 되어 메모리 초과가 났다.
# 그래서 따로 큐에 넣에줘서 같을때 cnt 값 출력해주기

from collections import deque
import sys
input = sys.stdin.readline

a,b = map(int,input().split())

#visited = [0]* (b+1)
#visited[a] = 1
que = deque([[a,1]])

while que:
    x,cnt = que.popleft()

    for i in [x*2,x*10+1]:
        if i == b:
            print(cnt+1)
            exit()
        elif 1<=i<b :
            que.append([i,cnt+1])
print(-1)