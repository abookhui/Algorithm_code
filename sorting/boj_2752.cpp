#include<stdio.h>
#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr[3];
    scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);

    for(int i=0;i<3;i++)for(int j=i+1;j<3;j++)if(arr[i]>arr[j])swap(arr[i],arr[j]);
    printf("%d %d %d",arr[0],arr[1],arr[2]);
}