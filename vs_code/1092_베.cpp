#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> crane;
vector<int> box;
stack<int> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,a;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        crane.push_back(a);
    }
    
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a;
        box.push_back(a);
    }
    sort(crane.begin(),crane.end(),greater<int>());
    sort(box.begin(),box.end(),greater<int>());

    if(crane[0]<box[0]){
        cout<<-1<<'\n';
        return 0;
    }  
    
    for(int i=m-1;i>=0;i--){
        s.push(box[i]);
    }

    int ans=0;
    while(!s.empty()){
        ans++;
        for(int i=0;i<n;i++){
            for(int j=0;j<s.size();j++){
                if(crane[i]>=box[j]){
                    //cout<<"crane : "<<crane[i]<<"\n";
                    //cout<<"s.top : "<<s.top()<<"\n";
                    box[j]='\0';
                    s.pop();
                    break;
                }
            }
        }
    }
    cout<<ans<<'\n';
}