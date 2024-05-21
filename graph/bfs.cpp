#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define num 1001
vector<int>graph[num];
vector<int>arr1,arr2;

int visited_b[num] = {0,};

void bfs(int node){
    if(visited_b[node]) return;
    queue<int> q;
    q.push(node);
    visited_b[node] = 1;

    while(!q.empty()){
        int n = q.front();
        q.pop();
        arr2.push_back(n);
        for(int i =0;i<graph[n].size();i++){
            int val = graph[n][i];
            if(!visited_b[val]){
                q.push(val);
                visited_b[val] =1;
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
    for(int i=1;i<=n;i++) sort(graph[i].begin(),graph[i].end());
        
    bfs(v);
    for(int i:arr2) printf("%d ",i);
}