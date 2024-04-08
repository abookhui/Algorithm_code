//좋은 친구
#include<iostream>
#include<queue>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    queue<int> q[21]; 
    
    long long cnt=0;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        int len = name.length();
        while(!q[len].empty() && i-q[len].front() > k) q[len].pop();
        // q[len]에 넣은 순위(i인덱스)들이 2보다 차이나면 다 빼버리고
        cnt += q[len].size(); // 값에 넣어줌
        q[len].push(i);
    } 
    cout<<cnt;
}
