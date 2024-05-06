#최대 힙

from queue import PriorityQueue

que = PriorityQueue()

for _ in range(int(input())):
    a = int(input())
    if a==0:
        if que.empty():
            print('-',0)
        else : print('-',que.get()*(-1))
    else :
        que.put(a*(-1))