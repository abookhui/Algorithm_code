# A. Yogurt Sale

import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,a,b = map(int,input().split())
    print(min(n //2 * b + n%2 * a,n*a))