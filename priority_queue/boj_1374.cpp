//boj_1374_강의실
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,s,e,r;
   
    vector<pair<int,int>> v;
    priority_queue<int,vector<int>,greater<int>> pq;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>r>>s>>e;
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