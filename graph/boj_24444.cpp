#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define Max 100002
vector<int> graph[Max];
int visited[Max] = {0,};
int ans[Max] = {0,};
int order = 1;

void bfs(int node){
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int k = q.front();
        q.pop();
        ans[k] = order++;
        for(int i=0;i<graph[k].size();i++){
            int next = graph[k][i];
            if(!visited[next]){
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

int main(){
    int n,m,v;

    cin>>n>>m>>v;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    bfs(v);
    for(int i=1;i<=n;i++){
         printf("%d\n",ans[i]);
    }

}   