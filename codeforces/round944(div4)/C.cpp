#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int a[2],b[2];

        scanf("%d %d %d %d",&a[0],&a[1],&b[0],&b[1]);
        sort(a,a+2);
        sort(b,b+2);
        int flag = 0;

        if (a[0]<=b[0] && b[0]<=a[1]){
            if(b[1]<=a[0] || b[1]>=a[1]){
                flag = 1;
            }
        }
        else if(a[0]<=b[1] && b[1]<=a[1]){
            if(b[0]<=a[0] || b[0]>=a[1]){
                flag = 1;
            }
        }
        if (flag) printf("YES\n");
        else printf("NO\n");

    }

}