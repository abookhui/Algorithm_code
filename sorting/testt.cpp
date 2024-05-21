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