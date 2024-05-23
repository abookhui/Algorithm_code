#include<iostream>
#include<map>    
#include<vector>

using namespace std;

int n;
int visited[500001] ={0,};
int dep[500001] = {0,};
map<int,vector<int>> tree;

void dfs(int node){
    visited[node] = 1;
    for(int nn : tree[node]){
        if(visited[nn]==0){
            dep[nn] = dep[node] + 1;
            dfs(nn);
        }
    }
}
int main(){
    
    scanf("%d",&n);
    

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
dfs(1);

int ans = 0;
for(int i=1;i<=n;i++){
    if(tree[i].size()==1){
        ans+=dep[i];
    }
}
if(ans%2==0) printf("No");
else printf("Yes");
}