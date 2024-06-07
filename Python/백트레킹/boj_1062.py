# 가르침 1602 - gold 4

import sys
import collections
from collections import defaultdict
input = sys.stdin.readline

n,k = map(int,input().split())
word = []
alph = defaultdict(int)


for i in range(n):
    str = input()
    tmp = str[4:-5]
    copy=''
    for s in tmp:
        if s in ['a','n','t','i','c']: continue
        alph[s] +=1
        copy+=s
    
    word.append(copy)  


if k<5 : 
    print(0) 
    exit()
alph = sorted(alph.keys())



#k-5
alphlen = len(alph) 
ans = 0 
def chk(lis):
    result =0
    for w in word:
        cnt = 0
        for i in w:
            if not i in lis: break
            cnt += lis.count(i)
        if cnt == len(w): result+=1
    return result
        
wordlen = min(k-5,alphlen)
def sol(idx,lis):
    global ans
    if idx > alphlen: return

    if len(lis) == wordlen:
        ans = max(chk(lis),ans)


    elif len(lis)< wordlen and idx < alphlen:
        lis.append(alph[idx])
        sol(idx+1,lis)
        lis.pop()
        sol(idx+1,lis)
    else : sol(idx+1,lis)

sol(0,[])
print(ans)

# antic 를 제외한 단어를 word에 저장해 이들로 구성될 수 잇는 글자의 수를 확인
# 이때 구성되는 글자의 길이는 k-5 혹은 alphlen이 더 작으면 alphlen 
# 그리고 이 구성된 글자로만 읽을 수 있는 단어 수 저장해고 최댓값 출력
