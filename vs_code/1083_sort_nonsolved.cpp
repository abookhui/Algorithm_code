// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int arr[50];
// //int ans[51][51];
// vector<vector<int>>ans(1000000,vector<int>(50,0));

// void swap_f(int *a, int *b){
//     int tmp=*a;
//     *a=*b;
//     *b=tmp;
// }

// void cpy_arr(int idx, int size){
//     for(int i=0;i<size;i++){
//         ans[idx][i]=arr[i];
//     }
// }

// int main(){
//     int s,n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cin>>s;
//     int ids=s;
//     while(s--){
//         for(int i=0;i<n;i++){
//             if(arr[i]>=arr[i+1]){
//                 continue;
//             }
//             swap_f(&arr[i],&arr[i+1]);
//             break;
//         }
//         cpy_arr(s,n); 
//     }
//     for(int i=0;i<n;i++){
//         printf("%d ",ans[s+1][i]);
//     }cout<<'\n';
// }

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[51];
int n,s;

void input_arr(){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void output_arr(){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
vector<int> store_arr(){
    vector<int>v;
    for(int i=0;i<n;i++){
        v.push_back(arr[i]);
    }

    return v;
}
int main(){
    vector<vector<int>>ans;
    cin>>n;
    input_arr();
    cin>>s;

    while(s--){
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                swap(arr[i],arr[i+1]);
                ans.push_back(store_arr());
                break;         
            }
        }
    }

    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }cout<<'\n';
    // }
    sort(ans.begin(),ans.end());

    for(int i=0;i<n;i++){
        cout<<ans[ans.size()-1][i]<<" ";
    }

}
