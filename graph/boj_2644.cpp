// // BOJ 2644 촌수계산

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<int>fam[101];
int visited[101]={0,};
int ans;

void dfs(int node,int end,int cnt){
    visited[node] = 1;
    if(node == end) ans = cnt;
    for(int i=0;i<fam[node].size();i++){
        int next = fam[node][i];
        if(!visited[next]) dfs(next,end,cnt+1);
    }
}

int main(){
    int n,v1,v2,m;
    cin>>n>>v1>>v2>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        fam[a].push_back(b);
        fam[b].push_back(a);
    }
    dfs(v1,v2,0);
    printf("%d",ans!=0?ans:-1);
}