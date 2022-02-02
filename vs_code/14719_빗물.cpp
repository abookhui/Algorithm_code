#include<iostream>
#include<vector> 
using namespace std;

int main(){
    int row,col,a;
    vector<int>h;

    cin>>row>>col;

    for(int i=0;i<col;i++){
        cin>>a;
        h.push_back(a);
    }
    int ans=0;
    for(int i=1;i<col-1;i++){
        int lo=0,ro=0,val;

        for(int j=0;j<i;j++) lo=(h[j]>lo)?h[j]:lo;
        for(int j=i+1;j<col;j++) ro=(h[j]>ro)?h[j]:ro;
        val=min(lo,ro)-h[i];
        if(val>=0) ans+=val;
    }
    
    cout<<ans<<'\n';
}