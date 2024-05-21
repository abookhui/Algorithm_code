#include<iostream>
#include<vector>
#include<queue>
#define inf 1000000
#define Size 300001
using namespace std;

vector<pair<int,int>> city[Size];
int dist[Size];

void dijkstra(int start){
    priority_queue<pair<int,int>>p;
    dist[start] = 0;
    p.push({start,0});

    while(!p.empty()){
        int now = p.top().first;
        int d = p.top().second;
        p.pop();

        if(dist[now] < d) continue; 

        for(int i=0;i<city[now].size();i++){
            int cost = d + city[now][i].second;
            int nn = city[now][i].first;
            if(cost < dist[nn]){
                dist[nn] = cost;
                p.push({nn,cost});
            }
        }
    }
}



int main(){
    int n,m,k,x;
    vector<int>ans;
    cin>>n>>m>>k>>x;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        city[a].push_back({b,1});
    }
    for(int i=1;i<=n;i++) dist[i] = inf;
    
    dijkstra(x);
    
    for(int i=1;i<=n;i++){
        if(dist[i] == k){
            ans.push_back(i);
        }
    }
    
    if(ans.size()<1) printf("%d\n",-1);
    else {
        for(int i=0;i<ans.size();i++){
            printf("%d\n",ans[i]);
        }
    }

}