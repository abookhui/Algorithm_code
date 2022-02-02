#include<iostream>
using namespace std;

int n,m,row=0,col=0,ans;
char map[51][51];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        bool is_X=false;
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]=='X') is_X=true;
        }
        if(!is_X) row++;
    }

    for(int j=0;j<m;j++){
        bool is_X=false;
        for(int i=0;i<n;i++){
            if(map[i][j]=='X') is_X = true;
        }
        if(!is_X) col++;
    }
    
    cout<<(row+col)-min(row,col)<<'\n';

}