#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int arr[100] = {1,23,4,5,1,4,52,34,45,23};
    int idx,tmp;

    for(int i=0;i<9;i++){
        int j = i;
        while(arr[j]>arr[j+1]){
            tmp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = tmp;
            j--;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}
/*삽입정렬

각 숫자를 적절한 위치에 삽입.

다른 정렬은 무조건 위치를 변경 but, 삽입정렬은 필요할 때만 위치를 바꾸게 됨 따라서 버블,선택보다는 빠름
10+9+8+..+1
왼쪽 정렬되어 있다 가정하기에 필요한 만큼만 이동 but 그래봤자 O(N^2)임
하지만 2 3 4 5 6 7 8 9 10 1 처럼 거의다 정렬이 되어있으면 효율적임
*/