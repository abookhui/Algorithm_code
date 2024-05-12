#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int arr[2];
        scanf("%d %d",&arr[0],&arr[1]);
        sort(arr,arr+2);
        printf("%d %d\n",arr[0],arr[1]);
    }

}
