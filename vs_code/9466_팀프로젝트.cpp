#include<iostream>

using namespace std;

int main(){

    int k,a,d;

    scanf("%d/%d/%d",&k,&d,&a);

    if(k+a<d||d==0){
        cout<<"hasu"<<'\n';
        return 0;
    }
    cout<<"gosu"<<'\n';
}