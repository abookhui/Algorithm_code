#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v,cpy,ans;
    for(int i=0;i<8;i++){
        int a;
        cin>>a;
        v.push_back(a);
        cpy.push_back(a);
    }
    sort(cpy.begin(),cpy.end(),greater<>());
    int sum=0,idx=0;
    for(int i=0;i<5;i++){
        sum += cpy[i];
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<5;j++){
            if(v[i]==cpy[j]){
                ans.push_back(i+1);
            }
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",sum); 
    for(int i:ans){
        printf("%d ",i);
    }
}