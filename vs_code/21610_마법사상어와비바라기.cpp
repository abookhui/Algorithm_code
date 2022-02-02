#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n,m;
int map[51][51];
bool visit[51][51];
vector<pair<int,int>> cloud;
vector<pair<int,int>> mov;
int dist[9][2]={{0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};  // 8방위

void call_map(){
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

void input(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mov.push_back({a,b});
    }

    cloud.push_back({n-1,0});   // 처음 비구름
    cloud.push_back({n-1,1});
    cloud.push_back({n-2,0});
    cloud.push_back({n-2,1});

    visit[n-1][0]=true;
    visit[n-1][1]=true;
    visit[n-2][0]=true;
    visit[n-2][1]=true;
}

void mov_cloud(int idx){   // 구름 움직이기 > 1단계
    memset(visit,false,sizeof(visit));

    for(int i=0;i<cloud.size();i++){
        int x = cloud[i].first;
        int y = cloud[i].second; 
        for(int j=0;j<mov[idx].second;j++){
            x+=dist[mov[idx].first][0];
            y+=dist[mov[idx].first][1];
            if(x>=n) x-=n;
            if(x<0) x+=n;
            if(y>=n) y-=n;
            if(y<0) y+=n;
        }
        cloud[i].first=x;
        cloud[i].second=y;  
    }

    for(int i=0;i<cloud.size();i++){
        int a=cloud[i].first;
        int b=cloud[i].second;
        visit[a][b]=true;
    }
}

void water_copybug(){
    int diago[4][2]={{-1,-1},{-1,1},{1,1},{1,-1}};

    for(int i=0;i<cloud.size();i++){  // 물의 양 1증가 > 2단계
        int a=cloud[i].first;
        int b=cloud[i].second;
        map[a][b]++;
    }

    for(int i=0;i<cloud.size();i++){  // 물복사버그 > 4단계
        int cnt=0;
        for(int j=0;j<4;j++){
            int x=cloud[i].first+diago[j][0];
            int y=cloud[i].second+diago[j][1];
            if(x<0||y<0||x>n||y>n) continue;
            if(map[x][y]>0) cnt++;
        }
        map[cloud[i].first][cloud[i].second]+=cnt;
    }
}
void raincloud(){
    for(int i=0;i<n;i++){    // 구름 생기는중 >5단계
        for(int j=0;j<n;j++){
            if(visit[i][j]) continue;
            if(map[i][j]<2) continue;
            map[i][j]-=2;
            cloud.push_back({i,j});
        }
    }
    memset(visit,false,sizeof(visit));

    for(int i=0;i<cloud.size();i++){
        visit[cloud[i].first][cloud[i].second]=true;
    }
}

void print_ans(){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=map[i][j];
        }
    }
    cout<<ans<<'\n';
}

void solve(){
    input();
    for(int i=0;i<m;i++){
        mov_cloud(i);
        water_copybug();
        cloud.clear();
        raincloud();
    }
    //call_map();
    print_ans();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}