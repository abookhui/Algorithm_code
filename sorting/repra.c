#include<stdio.h>
#include<string>

void print_arr(int *arr,int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }printf("\n");
}
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubble(int *arr,int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]> arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }   
    }

    print_arr(arr,len);
}
void select(int *arr,int len){
    for(int i=0;i<len;i++){
        int idx = i;
        for(int j=i+1;j<len;j++){
            if(arr[idx]>arr[j]){
                idx = j;
            }
        }
        swap(&arr[idx],&arr[i]);
    }

    print_arr(arr,len);
}
void insert(int *arr,int len){
    for(int i=0;i<len;i++){
        int idx = i;
        while(arr[idx] > arr[idx+1] && idx>=0){
            swap(&arr[idx],&arr[idx+1]);
            idx--;
        }
    }

    print_arr(arr,len);
}
void quick(int *arr,int start,int end){
    if(start>=end) return;
    int key = start;
    int low = end-1;
    int high = start+1;

    while(high <= low){
        while(arr[key]>=arr[high] && high<end) high++;
        while(arr[key]<= arr[low] && low>start) low--;
        if(high > low) swap(&arr[key],&arr[low]);
        else swap(&arr[low],&arr[high]);
    }
    quick(arr,start,low-1);
    quick(arr,low+1,end);
}
int main(){
    int arr[8] = {4,5,6,7,34,8,32,1};

    //bubble(arr,8);
    //select(arr,8);
    //insert(arr,8);

    quick(arr,0,8);
    print_arr(arr,8);
}