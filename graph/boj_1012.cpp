// boj_1012 유기농 배추 

#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int arr[50][50]={0,};
int n,m,k;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y){
    arr[x][y] = 0;

    for(int i=0;i<4;i++){
        int mx = x+ dx[i];
        int ny = y+ dy[i];

        if(mx < m && mx >= 0 && ny < n && ny >= 0)
            if(arr[mx][ny]) dfs(mx,ny);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n>>k;

        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;
            arr[a][b] = 1;
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";  
        for(int i=0;i<m;i++){
            memset(arr[i],0,n*sizeof(int));
        }
    }

}