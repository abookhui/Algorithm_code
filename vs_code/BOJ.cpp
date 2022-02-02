#include<iostream>
#include<vector>
#include<cstring>
#define max 10001

using namespace std;

int n, m;
int map[max][max];
vector<int> v[max];
int visited[max] = { 0, };
int ans=0;

void dfs(int x, int cnt) {
	if(cnt==4){
        ans=1;
        return;
    }
    visited[x]=1;

    for(int i=0;i<v[x].size();i++){
        int nx=v[x][i];
        if(visited[nx]==0){
            dfs(nx,cnt+1);
        }
        if(ans==1){
            return;
        }
    }
    visited[x]=0;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) { 
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
        v[b].push_back(a);

	}

	for (int i = 0; i < n; i++) {
        memset(visited,0,sizeof(visited));
		dfs(i,0);
        if(ans==1) break;
    }

    if(ans==1){
        cout<<1<<'\n'; 
        return 0;
    }
    cout<<0<<'\n';
}