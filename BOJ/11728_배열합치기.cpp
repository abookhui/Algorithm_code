#include<iostream>
#define Max 1000001
using namespace std;

int n,m;
int a[Max],b[Max];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    int x=0,y=0;
    while(x<n&&y<m){
        if(a[x]<b[y]) printf("%d ",a[x++]);
        else printf("%d ",b[y++]);
    }

    while(x<n) printf("%d ",a[x++]);
    while(y<m) printf("%d ",b[y++]);
}