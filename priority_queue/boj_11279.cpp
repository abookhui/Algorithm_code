//boj_11279 최대 힙
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

int main(){
    int n, x;
    priority_queue<int> pq;

    scanf("%d",&n);

    while(n--){
        scanf("%d",&x);
        if(x == 0 && pq.empty()) printf("0\n");
        else if(x == 0 && !pq.empty()) {printf("%d\n",pq.top()); pq.pop();}
        else if(x > 0) pq.push(x);
    }
}