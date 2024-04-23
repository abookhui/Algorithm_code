// boj 2309 일곱 난쟁이 

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sum =0;
    int arr[9];
    pair<int,int>idx;
    for(int i=0;i<9;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    sort(arr,arr+9);
    sum-=100;

    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            int cmp = arr[i] + arr[j];
            if(cmp==sum){
                idx.first=i; idx.second=j;
                break;
            }
        }
    }

    for(int i=0;i<9;i++){
        if(i != idx.first && i != idx.second) printf("%d\n",arr[i]);
    }
}