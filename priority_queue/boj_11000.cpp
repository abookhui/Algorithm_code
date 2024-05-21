// boj_11000 강의실 배정
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int,int>> v;
    priority_queue<int,vector<int>,greater<int>> pq;
    int n,start,end,cnt=0;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end());

    for(auto w : v){
        if(!pq.empty()){
            if(w.first < pq.top()) cnt++;
            else pq.pop();
        }
        else cnt++;
        pq.push(w.second);
    }
    cout<<cnt;
}