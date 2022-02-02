#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long>v1;
vector<long long>v2;

int main(){

    long long n,ex;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ex;
        v1.push_back(ex);
        v2.push_back(i);
    }

    sort(v1.begin(),v1.end());
    
    long long ans=0;
    for(int i=0;i<v1.size();i++){
        long long val = v2[i]-v1[i];
       
        ans+=(val>=0)?val:val*(-1);
    }
    cout<<ans<<'\n';

}