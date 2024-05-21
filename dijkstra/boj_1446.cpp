#include<iostream>
#include<queue>
#include<vector>
#define inf 1000000
#define Size 10000
using namespace std;
vector<pair<int,int>>map[Size];
int dist[Size];

void dijkstra(int start){
    priority_queue<pair<int,int>>p;
    dist[start] = 0;
    p.push({start,0});

    while(!p.empty()){
        int now = p.top().first;
        int d = p.top().second;
        p.pop();

        if(dist[now] > d) continue;

        for(int i=0;i<map[now].size();i++){
            int cost = d + map[now][i].second;
            int nn = map[now][i].first;
            if(cost < dist[nn]){
                dist[nn] = cost;
                p.push({nn,cost});
            }
        } 
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int a,b,d;
        cin>>a>>b>>d;
        map[a].push_back({b,d});
    }

    for(int i=0;i<Size;i++){
        dist[i] = inf;
    }

    dijkstra(0);

    int ans =0;
    int cnt=0;
    int pri_val=0;
    for(int i=1;i<=m;i++){
        ans += 1;
        cnt +=1;
        if(dist[i] != inf){
            //printf("i: %d dist[%d]: %d cnt: %d ans: %d",i,i,dist[i],cnt,ans);
            ans = ans  - cnt - pri_val + dist[i];
            //printf(" pri: %d --ans == %d\n",pri_val,ans);
            cnt = 0;
            pri_val = dist[i];
        }
        
    }    
    printf("%d\n",ans);
}