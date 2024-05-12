#include<iostream>
using namespace std;

int main(){
    int n,m,a; 
    int ans = 0;
    cin>>n;
    int menu[11];
    for(int i=0;i<n;i++){
        scanf("%d",&menu[i]);
    }

    cin>>m;
    while(m--){
        cin>>a;
        ans += menu[a-1];
    }
    printf("%d\n",ans);
}