#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//모노톤

int main(){
    int n; 
    vector<int> v,ans;
    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top() <= v[i]) s.pop();
        if(s.empty()) ans.push_back(-1);
        else ans.push_back(s.top());
        s.push(v[i]);
    }
    for(int i=ans.size()-1;i>=0;i--){
        printf("%d ",ans[i]);
    }
}