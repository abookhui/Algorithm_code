#include<iostream>
#include<vector>
#include<queue>
#define inf 1000000
using namespace std;

vector<pair<int,int>>node[3]; // 노드-거리
int dist[3];

void dijkstra(int start){
    priority_queue<pair<int,int>>p; // 
    p.push({start,0});  // 시작지점과 시작지점으로 이동거리 == 0 push
    dist[start] = 0;

    while(!p.empty()){
        int now = p.top().first; 
        int d = p.top().second;
        p.pop();

        if(dist[now]<d) continue;  // 이미 최단 거리 정보가 있으면 넘어감

        for(int i=0;i<node[now].size();i++){
            int nn = node[now][i].first;
            int cost = d + node[now][i].second;
            if(cost < dist[nn]){
                dist[nn] = cost;
                p.push({nn,cost});
            }
        }
    }

}
int main(){
    for(int i=0;i<3;i++){
        dist[i] = inf;
    }
    node[0].push_back({1,5});
    node[0].push_back({2,1});
    node[2].push_back({1,3});

    dijkstra(0);

    for(int i=0;i<3;i++){
        cout<<dist[i]<<endl;
    }
}