#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int arr[100] = {1,23,4,5,1,4,52,34,45,23};
    int idx,tmp;
    for(int i=0;i<10;i++){
        int min = 999;
        for(int j=i; j<10; j++){
            if(min>arr[j]){
                min = arr[j];
                idx = j;
            }      
        }
        tmp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = tmp;
    }
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}

/*
 선택 정렬
 가장 작은 값을 선택해서 제일 앞으로 보냄
 1 2 3 4 5 6 7 8 9 10

 10 + 9 +8...+1 즉 10번의 확인
 등차 수열
 10 * (10+1) / 2 
  n *(n+1)  즉 n^2 수행시간
   시간 복잡도 O(N^2) 최악

*/