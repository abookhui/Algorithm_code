#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int,int>>v;

int main(){
    int n,p,q;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p>>q;
        v.push_back({p,q});
    }
    sort(v.begin(),v.end());

    
}