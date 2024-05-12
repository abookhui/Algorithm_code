#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main(){
    string cmp,sub;
    int n,cnt=0;
    cin>>cmp;
    cmp = cmp.substr(0,5);
    cin>>n;

    for(int i=0;i<n;i++){
        string str;
        cin>>sub;
        str = sub.substr(0,5);
        if(str.compare(cmp)==0) cnt++;
    }
    cout<<cnt;
}