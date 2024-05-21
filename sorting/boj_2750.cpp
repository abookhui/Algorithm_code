#include<stdio.h>
#include<iostream>
#define num 1000
using namespace std;
void inputArr(int *arr,int n) {for(int i=0;i<n;i++) scanf("%d",&arr[i]);}
void outputArr(int *arr,int n) {for(int i=0;i<n;i++) printf("%d\n",arr[i]);}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) swap(&arr[j],&arr[i]);
        }
    }
}
int main(){
    int n, arr[num];
    cin>>n;
    inputArr(arr,n);
    sort(arr,n);
    outputArr(arr,n);



}