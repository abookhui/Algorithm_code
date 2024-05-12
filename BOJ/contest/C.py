from collections import Counter
n,d = map(int,input().split())

name = []
s = []
for _ in range(n):
    ans = 1
    def dfs(a):
        global ans
        stack = []
        stack.append(a)
        cnt = 0
        while stack:
            x = stack.pop()
            fx,bx = x+1,x-1

            if 0<=fx<d:
                if not visited[fx] and line[fx] =='.':
                    cnt+=1
                    visited[fx] = 1
                    stack.append(fx)
            if 0<=bx<d:
                if not visited[bx] and line[bx] =='.':
                    cnt+=1
                    visited[bx] = 1
                    stack.append(bx)
        ans = max(cnt,ans)
        return ans

    visited = [0]*d
    line = []
    tmp = input().split()
    line.extend(tmp[:d])
    name.append(tmp[d:])
    
    max_val = 0
    for i in range(d):  
        if line[i] == '.' and not visited[i]:
            result = dfs(i)
            if max_val < result: max_val = result
    s.append(max_val)  

counter = Counter(s)

print(len(dict(counter)))
for i in range(len(name)):
    print(s[i],''.join(name[i]))
