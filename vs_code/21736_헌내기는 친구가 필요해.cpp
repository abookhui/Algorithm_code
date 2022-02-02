#include<iostream>

using namespace std;

int row,col;
int map[600][600];
int chk[600][600]={0,};
char c;
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int cnt=0;

bool Is_t(int a,int b){
    if(a>=0&&a<row&&b>=0&&b<col){
        return true;
    }
    return false;
}

void dfs(int x,int y){

    for(int i=0;i<4;i++){
        int nx=x+d[i][0];
        int ny=y+d[i][1];

        if(Is_t(nx,ny)&&map[nx][ny]!=0&&chk[nx][ny]==0){
            if(map[nx][ny]==2){
                cnt++;
            }
            chk[nx][ny]=1;
            dfs(nx,ny);
        }
    }

}

int main(){
    scanf("%d %d",&row,&col);
    int a,b;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>c;
            if(c=='O'){
                map[i][j]=1;
            }
            else if(c=='X'){
                map[i][j]=0;
            }
            else if(c=='I'){
                a=i;
                b=j;
                map[i][j]=-1;
                
            }
            else if(c=='P'){
                map[i][j]=2;
            }
        }
    }

    dfs(a,b);

    if(cnt==0){
        cout<<"TT"<<'\n';
        return 0;
    }
    cout<<cnt<<'\n';
}