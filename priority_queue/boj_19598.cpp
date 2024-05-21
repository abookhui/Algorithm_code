#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s,e;

    vector<pair<int,int>> v;
    priority_queue<int,vector<int>,greater<int>> pq;

    cin>> n;
    
    for(int i=0;i<n;i++){
        cin>>s>>e;
        v.push_back({s,e});
    }

    sort(v.begin(),v.end());

    int cnt=0;
    for(int i=0;i<n;i++){
        if(!pq.empty()){
            if(v[i].first < pq.top()) cnt++; 
            else pq.pop();
        }
        else cnt++;
        pq.push(v[i].second);
    }
    cout<<cnt;
}