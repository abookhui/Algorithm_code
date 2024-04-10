//boj_13904 과제
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue> 
using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<pair<int,int>> v;
    priority_queue<int,vector<int>, greater<int>> pq;
    int n,deadline,score, ScoreSum =0;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>> deadline >> score;
        v.push_back({deadline,score});
    }
    sort(v.begin(),v.end(),cmp);

    for(auto w : v){
        if(pq.size() < w.first){ // size는 지난 일   ∴ 지난 일 < 남은 일 이면 넣어줌
            pq.push(w.second);
        }
        else { // 남은 일이 더 적으면 제일 작은 점수와 지금 점수 비교해서 바꾸기
            if(pq.top() < w.second){
                pq.pop(); pq.push(w.second);
            }
        }
        
    }
    while(!pq.empty()){
        ScoreSum += pq.top();
        pq.pop();
    }
    cout<<ScoreSum;
}