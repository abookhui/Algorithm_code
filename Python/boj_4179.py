#불 !

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def Change(s):
    if s == '#': return 1  # 벽
    elif s == '.' or s == 'J' : return 0 # 길
    elif s == 'F' : return 2 # 불

n,m = map(int,input().split())
arr = []

def run(jx,jy,fx,fy):

    #arr[fx][fy] += 1

    for i in range(4):
        nfx = fx+dx[i]
        nfy = fy+dy[i]

        if nfx>=0 and nfy >=0 and nfx < n and nfx < m:
            arr[nfx][nfy] += 1

    chk =0
    for i in range(4):
        njx = jx+dx[i]
        njy = jy+dy[i]

        if njx>=0 and njy >=0 and njx < n and njx < m:  
            if arr[njx][njy] == 0:
                chk+=1
                jx = njx
                jy = njy
        if njx >= n or njy >= m:
            return True
    if chk == 0:
        return False        


for i in range(n):
    col = []
    line = input()
    for j in range(len(line)):
        if line[j]=='J':
            jx = i
            jy = j
        elif line[j]=='F':
            fx = i
            fy = j

        col.append(Change(line[j]))

    arr.append(col)

cnt = 0
while True:
    cnt+=1
    if not run(jx,jy,fx,fy):
        print('IMPOSSIBLE')
        break
    else :
        print(cnt+1)
        break