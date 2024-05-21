#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool cmp (pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first > b.first;
    else return a.second < b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<pair<int,int>> v;
    priority_queue<int,vector<int>,greater<int>> pq;
    int n, d, p, money = 0;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>p>>d;
        v.push_back({p,d});
    }   
    sort(v.begin(),v.end(),cmp);
    for(auto w : v){
        if(pq.size() < w.second) pq.push(w.first);

        else {
            if(pq.top() < w.first) {
                pq.pop(); pq.push(w.first);
            }
        }
    }

    while(!pq.empty()) {
        money += pq.top();
        pq.pop();
    }
    cout<<money;
}