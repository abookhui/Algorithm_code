#include<stdio.h>
#include<iostream>

using namespace std;

int cnt=0,n,m;
char arr[51][51];
void chk1(int a,int b){
    for(int i=b+1;i<m;i++){
        if(arr[a][i] == '-'){
            arr[a][i] = 0;
        }
        else return;
    }
}
void chk2(int a,int b){
    for(int i=a+1;i<n;i++){
        if(arr[i][b] == '|'){
            arr[i][b] = 0;
        }
        else return;
    }
}
int main(){
    cin>>n>>m;

	for (int i = 0; i < n; i++) {
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
	}

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]== '-'){
                chk1(i,j);
                cnt++;
            }
            else if(arr[i][j]=='|'){
                chk2(i,j);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
 }