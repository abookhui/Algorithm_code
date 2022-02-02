#include<iostream>

using namespace std;

typedef struct{
    int num;
    int arr[10];
}Team;

Team t[11];
int sovling_p[11]={1,};
int map[11][11];
int n,m;


int main(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>t[i].num;
        for(int j=0;j<t[i].num;j++){
            cin>>t[i].arr[j];
        }
    }
    

}