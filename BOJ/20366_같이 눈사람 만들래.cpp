#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> h;
//vector<vector<int>> snow;
int ans =1e9;

void input(){
    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        h.push_back(a);
    }

    sort(h.begin(),h.end());
}

void sol(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int lo=0,ro=n-1;
            while(1){
                while(lo==i||lo==j) lo++;
                while(ro==i||ro==j) ro--;
                if(lo>=ro) break;

                int val = h[i]+h[j]-h[lo]-h[ro];
                ans = min(ans,abs(val));
                
                if(val>0) lo++;
                else ro--;
            }
        }
    }
    cout<<ans<<'\n';
}

void solve(){
    input();
    sol();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}

// void combi(){
//     vector<int> ind,v;

//     for(int i=0;i<n;i++) v.push_back(i);
//     for(int i=0;i<4;i++) ind.push_back(1);
//     for(int i=0;i<n-4;i++) ind.push_back(0);

//     sort(ind.begin(),ind.end());

//     do{
//         vector<int> tmp;
//         for(int i=0;i<ind.size();i++){
//             if(ind[i]==1){
//                 tmp.push_back(h[i]);
//             }
//         }
//         snow.push_back(tmp);
//     }while(next_permutation(ind.begin(),ind.end()));

//     sort(snow.begin(),snow.end());

// }

// int min_val(vector<int> v){
//     return min(abs((v[0]+v[1])-(v[2]+v[3])),min(abs((v[1]+v[2])-(v[0]+v[3])),abs((v[3]+v[1])-(v[2]+v[0]))));
// }

// void sol1(){
//     int ans=200;

//     for(int i=0;i<snow.size();i++){
//         int val = min_val(snow[i]);
//         if(ans>val){
//             ans = val;
//             if(ans == 0) break;
//         }
//     }
//     cout<<ans<<'\n';
// }
