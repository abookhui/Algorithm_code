#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXSize 300001
using namespace std;

int n,k;
pair<int, int> jewerly[MAXSize];
int bag[MAXSize];


long long solve(){
    int idx = 0;
    long long ans = 0;
    priority_queue<int> pq;
    
    for(int i=0;i<k;i++){
        while(idx<n && jewerly[idx].first <= bag[i]){
            pq.push(jewerly[idx++].second);
        }
        if(!pq.empty()){
            ans += pq.top(); pq.pop();
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>k;

    for(int i=0;i<n;i++) cin>>jewerly[i].first>>jewerly[i].second;
    for(int i=0;i<k;i++) cin>>bag[i];
    sort(jewerly,jewerly+n); sort(bag,bag+k);

    cout<<solve();

}