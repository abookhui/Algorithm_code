//boj_11286 절댓값 힙
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
    int n,x,abs;
    scanf("%d",&n);
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq; // 오름차순 우선순위 큐 

    while(n--){
        scanf("%d",&x);
        if(x == 0 && pq.empty()) printf("0\n");
        else if( x == 0 && !pq.empty()){
            abs = pq.top().second;
            if(abs<0) printf("%d\n",(pq.top().first)*(-1));
            else printf("%d\n",pq.top().first);
            pq.pop();
        }
        else if(x>0) pq.push({x,1});
        else if(x<0) {x *= (-1);pq.push({x,-1});}
    }
}