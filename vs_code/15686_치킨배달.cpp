#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,N,R;
int map[51][51];

vector<pair<int,int>>v1,v2;
vector<int> arr;
int com[100];
vector<vector<int>>vec;

void input(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==1) v1.push_back({i,j});
            if(map[i][j]==2) v2.push_back({i,j});
        }
    }

    for(int i=0;i<v2.size();i++){
        arr.push_back(i);
    }
    N=v2.size();

}

int dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

void combination(int N,int R, int q){
    if(R==0){
        vector<int> v;
        for(int i=q-1;i>=0;i--){
            v.push_back(com[i]);
        }
        vec.push_back(v);
    }
    else if(N<R) return;

    else {
        com[R-1]=arr[N-1];
        combination(N-1,R-1,q);
        combination(N-1,R,q);
    }
}


void combi() {  
    vector<int> ind;
    
    for(int i=0;i<m;i++){
        ind.push_back(1);
    }

    for(int i=0;i<N-m;i++){
        ind.push_back(0);
    }
    sort(ind.begin(),ind.end());

    do{
        vector<int> v;
        for(int i=0;i<N;i++){
            if(ind[i]==1){
                v.push_back(arr[i]);
            }
        }
        vec.push_back(v);
    }while(next_permutation(ind.begin(),ind.end()));
}
void sol(){
    //combination(N,m,m);
    combi();
    int answer=99999;
    for(int t=0;t<vec.size();t++){ 
        int ans=0;
        for(int i=0;i<v1.size();i++){
            int val=99999;
            for(int j=0;j<vec[t].size();j++){
                val=min(dist(v1[i].first,v1[i].second,v2[vec[t][j]].first,v2[vec[t][j]].second),val);
            }
            ans+=val;
        }
        answer=min(ans,answer);
    }
    cout<<answer<<'\n';
}

void solve(){
    input();
    sol();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve(); 
    return 0;
}