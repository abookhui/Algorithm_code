#include<stdio.h>
#include<iostream>
using namespace std;


void quickSort(int *data,int start, int end){
    if(start >= end) return; // 원소가 1개인 경우
    int key = start; // 키는 첫번째 원소
    int i = start+1;  // 원쪽 출발 지점
    int j = end; // 마지막 값, 오른쪽 출발 지점
    int temp;

    while(i<=j){ // 엇갈릴 때까지 반복
        while(data[i]<=data[key]&&i<end) {// 키 값보다 큰 값을 만날때까지 오른쪽으로 이동
            i++;
        }
        while (data[j]>=data[key] && j>start) { // 키 값보다 작은 값을 만날때까지 왼쪽 이동  
            j--;
        }
        if(i>j){ // 현재 엇갈린 상태면 기 값과 교체
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else{ // 엇갈리지 않음>> 큰값과 작은값 교체
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }
    //제귀적 함수
    quickSort(data,start,j-1);
    quickSort(data,j+1,end);
}

int main(){
    int num = 10;
    int data[10] = {2,3,7,8,1,5,9,6,10,4};

    quickSort(data,0,num-1);

    for(int i=0;i<num;i++){
        printf("%d ",data[i]);
    }
}
/*
퀵 정렬 

특정한 값을 기준으로 큰 숫자와 작은 숫자를 나눔
분할 정복 알고리즘으로 평균속도가 O(n*logn)

퀵정렬에는 기준 값(pivot)이 있음 보통 첫번째 원소를 pivot으로 설정

거의 정렬이 되어있으면 시간복잡도는 O(N^2)에 가까움 
*/

#include<stdio.h>
#include<iostream>
using namespace std;
#define num 10

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *data,int start,int end){
    if(start>=end) return;
    int temp,pivot=start;
    int high = start+1;
    int low = end;

    while(high<=low){  // high <= low
        while (data[high] <= data[pivot] && high<=end) high++;
        while (data[low] >= data[pivot] && low >start) low--;  //low > start
        if(high<=low) swap(&data[high],&data[low]);
        else swap(&data[low],&data[pivot]);

    }
    quickSort(data,start,low-1);
    quickSort(data,low+1,end);
}

int main(){
    int data[num] = {1,10,5,8,7,6,4,3,2,9};
    quickSort(data,0,num-1);

    for(int i=0;i<num;i++){
        printf("%d ",data[i]);
    }
}