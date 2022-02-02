#include<iostream>
#include<vector>
using namespace std;


int n,m;
int map[51][51];
bool visit[51][51];
vector<pair<int,int>>mov;
int di[8][2]={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};


void input(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }   
    int d,s;
    for(int i=0;i<m;i++){
        cin>>d>>s;
        mov.push_back({d,s});
    }
}

void cloud_mov(int idx){
    
}

void sol(){
    

}

void solve(){
    input();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}