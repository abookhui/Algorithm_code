#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int t,x;
    cin>> t;
    while(t--){
        cin>>x;
        int max_val = 0;
        int idx;
        for(int y=1;y<x;y++){
            int val = gcd(x,y) + y;
            if(max_val < val) {
                max_val = val;
                idx = y;
            }
        }
        printf("%d\n",idx);
    }
}
