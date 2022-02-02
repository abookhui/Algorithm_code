#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int a,b,n,m;
vector<int> v[1001];
int dist[1001];
vector<bool>visit;

void input(){
    cin>>a>>b>>n>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

void dijkstra(int s){
    priority_queue<pair<int,int>>q;
    q.push({0,s});
    dist[s]=0;
    visit[s]=true;

    while(!q.empty()){
        int x=q.top().first;
        int y=q.top().second;
        q.pop();

        if(x>dist[y]) continue;

        for(int i : v[y]){
            int val = y+1;
            if(val <<dist[i]){
                dist[i] = val;
                q.push({val,i});
            }
        }
    }
}

void solve(){
    input();
    dijkstra(a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}