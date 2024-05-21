#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<string.h>  
using namespace std;

int main(){
    int n,m;

    cin>>n>>m;
    long long ans = n * (n - 1) / 2;
    ans *=  (m * (m - 1) / 2);
    printf("%lld\n",ans);

}