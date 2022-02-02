#include<iostream>

using namespace std;
int dx,dy,bx,by,jx,jy;

int br[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int dr[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

void Bessie(){
    int cmp=1001,x;
    for(int i=0;i<8;i++){
        int val=abs(jx-bx+br[i][0])+abs(jy-by+br[i][1]);
        if(val<=cmp){
            cmp=val;
            x=i;
        }
    }
    bx+=br[x][0]; by+=br[x][1];
}

void Daisy(){
    int cmp=1001,x;
    for(int i=0;i<4;i++){
        int val=abs(jx-dx+dr[i][0])+abs(jy-dy+dr[i][1]);
        if(val<=cmp){
            cmp=val;
            x=i;
        }
    }
    dx+=dr[x][0]; dy+dr[x][1];
}


int main(){
    cin>>bx>>by>>dx>>dy>>jx>>jy;

    int cnt_d=0,cnt_b=0;

    while(!(bx==jx&&by==jy)){
        Bessie();
        cnt_b++;
    }
    while(!(dx==jx&&dy==jy)){
        Daisy();
        cnt_d++;
    }
    
    string ans = (cnt_d==cnt_b)?"tie":((cnt_d>cnt_b)?"daisy":"bessie");
    cout<<ans<<'\n'; 
}