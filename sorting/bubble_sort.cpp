#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int arr[100] = {1,23,4,5,1,4,52,34,45,23};
    int idx,tmp;

    for(int i=0;i<10;i++){
        for(int j=0;j<9-i;j++){
            if(arr[j]>arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}
/*버블 정렬

옆에 있는 값과 비교해서 더 작은 값을 앞으로 보냄.

구현은 가장 쉽다만 효율은 비비비효율임.

등차 수열
n * (n + 1) / 2
시간 복잡도  O(n^2) 

*/