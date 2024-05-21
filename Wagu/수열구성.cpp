#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int n,k,a;

set<pair<int,int>> combin(vector<int> num) {
    set<pair<int,int>> result;
    sort(num.begin(), num.end());
    do {
        for (int i = 1; i <= num.size(); i++) {
            string str = "";
            for (int j = 0; j < i; j++) {
                str += to_string(num[j]);
            }
            if (str[0] != '0') {
                int val = stoi(str);
                if(val > k) {
                    int rest = val % k;
                    result.insert({val,rest});
                }
            }
        }
    } while (next_permutation(num.begin(), num.end()));

    for(int i=0;i<num.size();i++){
        string str = to_string(num[i]);
        for(int j=1;j<n;j++){
            str+=to_string(num[i]);
            if(stoi(str) > k){
                result.insert({stoi(str),num[i]});
            }
        }
    }
    return result;
}

void print(set<pair<int,int>> numbers) {
    for (auto &num : numbers) {
        printf("%d %d\n",num.first ,num.second );
    }
}

int main() {
    // vector<int> num; 
    // cin>>n>>k;

    // for(int i=0;i<n;i++){
    //     cin>>a;
    //     num.push_back(a);
    // }
    // set<pair<int,int>> numbers = combin(num);

    
    // // print(numbers);
    // // cout<<'\n';
    // map<int,int> m;

    // for (const auto &p : numbers) {
    //     if (m.count(p.second) == 0) {
    //         m[p.second] = p.first;
    //     } else {
    //         m[p.second] = min(m[p.second], p.first);
    //     }
    // }

    // for(int i=0;i<k;i++){
    //     bool chk=1;
    //     for (const auto &p : m) {
    //         if(p.first == i){
    //             printf("%d ",p.second); chk=0;
    //             break;
    //         }
    //     }
    //     if(chk) printf("-1 ");

    // }
    printf("%d %d\n",12%9,21%9);
}