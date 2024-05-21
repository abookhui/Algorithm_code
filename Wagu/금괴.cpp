#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<string.h>  
#define MaxSize 1000000
using namespace std;


// 5
// 4 2 2 5 8
// 전 w  <  현 w end

long long arr[MaxSize];
long long v[MaxSize] = {0, };
int n,w;
int visited[MaxSize] = {0, };

long long fun1(int idx,long long ans){
    //long long ans = 0;

    visited[idx] = 1;
    long long val = arr[idx];
    long long ri = arr[idx+1];

    if(idx >= n) {
        return ans;
    }  
    if(ri > val){
        return ans;
    }

    else if(ri <= val){
        if(!v[idx+1]) fun1(idx+1,ans+ri);
        else fun1(idx+1,ans);
    }
    
}
long long fun2(int idx,long long ans){
    visited[idx] = 1;

    long long val = arr[idx];
    long long le = arr[idx-1];

    if(idx <= 0)  return ans;
    if(le > val) return ans;
    

    else if(le <= val){
        
        if(!v[idx-1]) fun2(idx-1,ans+le);
        else fun2(idx-1,ans); 
    }
}

int main(){
    
    cin>> n;

    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    
    long long ans=0;
    int room;
    // for(int i=1;i<n-1;i++){
        
    //     long long cnt=0;
    //     memset(visited,0,n*sizeof(int));
        
    //     cnt += fun1(i,arr[i]);
    //     cnt += fun2(i,arr[i]);

    //     ans = ans<cnt ? cnt-arr[i] : ans;

    // }
    sort(arr,arr+n);
    
    printf("%lld\n",ans);
}