#include<iostream>
#include<algorithm>

using namespace std;

typedef struct {
    int num;
    int arr[11];
}team;

team t[11];
int n,m;
int chk[11]={0,};
bool cmp(const team a, const team b){
    if(a.num==b.num){
        int c=sizeof(a.arr);
        int d=sizeof(b.arr);
        return c<d;
    }
    return a.num > b.num;
}
int main(){
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++){
        cin>>t[i].num;

        for(int j=0;j<t[i].num;j++){
            cin>>t[i].arr[j];
        }
    }
    sort(t,t+m,cmp);

    int cnt=0;
    for(int i=0;i<m;i++){
        int id=0;
        for(int j=0;j<t[i].num;j++){
            if(chk[t[i].arr[j]]==1){
                continue;
            }
            else{
                id++;
                chk[t[i].arr[j]]=1;
            }  
        }
        if(id>0){
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        if(chk[i]!=1){
            cout<<-1;
            return 0;
        }
    }
    cout<<cnt<<'\n';
}
