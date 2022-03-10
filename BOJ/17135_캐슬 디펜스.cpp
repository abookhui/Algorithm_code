#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,d;
int ans=0,idx=0;
int map[16][16];
vector<vector<int>>ar;
vector<int>v;

void input(){
    cin>>n>>m>>d;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<m;i++){
        v.push_back(i);
    }

}

void combi() {  
    vector<int> ind; 
    for(int i=0;i<3;i++){
        ind.push_back(1);
    }

    for(int i=0;i<n-3;i++){
        ind.push_back(0);
    }
    sort(ind.begin(),ind.end());

    do{
        vector<int> vv;
        for(int i=0;i<ind.size();i++){
            if(ind[i]==1){
                vv.push_back(v[i]);
            }
        }
        ar.push_back(vv);
    }while(next_permutation(ind.begin(),ind.end()));

    sort(ar.begin(),ar.end());

}


bool dist(int x1,int y1, int x2, int y2){
    int di=abs(x1-x2)+abs(y1-y2);
    return (di<=d)?true:false;
}

void sol(){
    
}

void solve(){
    input();
    combi();

    for(int i=0;i<ar.size();i++){
        for(int j=0;j<ar[i].size();j++){
            printf("%d ",ar[i][j]);
        }cout<<"\n";
    }
}
int main(){
    solve(); 
}