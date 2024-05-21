#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define num 100001
using namespace std;

vector<int> graph[num];
int visited[num] = {0,};
int sum[num] = {0,};
int cnt =0;

void dfs(int node){
    if(visited[node]) return;
    visited[node]=1;
    sum[node] = ++cnt;
    for(int i=0;i<graph[node].size();i++){
        int n = graph[node][i];
        if(!visited[n]) {
            dfs(n);
        }
    }
}
int main(){
    
    int n,m,r;
    //cin>>n>>m>>r;
    scanf("%d %d %d",&n,&m,&r);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        //sort(graph[i].begin(),graph[i].end(),greater<int>()); 내림차순
        sort(graph[i].begin(),graph[i].end());  // 오름차순
    }
    dfs(r);
    for(int i=1;i<=n;i++){
        printf("%d\n",sum[i]);
    }
}