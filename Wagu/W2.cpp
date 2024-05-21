#include <iostream>
#include <vector>  
#include<algorithm>
#include<map>

using namespace std;

vector<int> inputArr(int n){
    vector<int> v(n);
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    return v;
}

int cass(int k, vector<int> v){
    int ans =0;
    map<int,int> m;
    for(int i=0;i<v.size();i++){
        int idx = k-v[i];
        ans += m[idx];
        m[v[i]]++;
    }
    return ans;
}
int main() {
    int n,k, answer;

    cout<< "k : ";
    cin>> k;
    for(int repet = 0; repet<6;repet++){
        vector<int> v;

        cin>>n;
        v = inputArr(n);
        //sort(v.begin(),v.end());
        
        answer = cass(k,v);

        printf("%d\n",answer);
    }
    

    
}
