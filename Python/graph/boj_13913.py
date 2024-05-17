# 숨바꼭질4 gold 4
# 이동 위치 리스트로 저장해서 시간초과 남 >> dict 로 변경하기

from collections import deque
import sys
input = sys.stdin.readline
Size = 100001

n,k = map(int,input().split())

visited = dict()
que = deque([n])
visited[n] = n

while que:
    x = que.popleft()

    if x == k:
        cur = x
        break

    for nx in [x-1, x+1, x*2]:
        if 0<=nx<Size and nx not in visited:
            visited[nx] = x
            que.append(nx)

ans = deque()
cnt =0

while visited[cur] != cur:
    ans.appendleft(cur)
    cur = visited[cur]
    cnt+=1
ans.appendleft(cur)
print(cnt)
print(*ans)
        