// #include<stdio.h>

// //#define num 1000000
// using namespace std;

// //void inputArr(int* arr, int n) { for (int i = 0; i < n; i++) scanf("%d", &arr[i]); }
// //void outputArr(int* arr, int n) { for (int i = 0; i < n; i++) printf("%d\n", arr[i]); }
// //void swap(int* a, int* b) {
// //    int temp = *a;
// //    *a = *b;
// //    *b = temp;
// //}

// void quickSort(int* arr, int start, int end) {
//     if (start >= end) return;
//     int pivot = start, high = start + 1, low = end;
//     while (high <= low) {
//         while (arr[high] <= arr[pivot] && high <= end) high++;
//         while (arr[low] >= arr[pivot] && low > start) low--;
//         if (low < high)
//         {
//             //swap(&arr[low], &arr[pivot]);
//             int temp = arr[low];
//             arr[low] = arr[pivot];
//             arr[pivot] = temp;
//         }
//         else {
//             //swap(&arr[low], &arr[high]); 
//             int temp = arr[low];
//             arr[low] = arr[high];
//             arr[high] = temp;
//         }
//     }
//     quickSort(arr, start, low - 1);
//     quickSort(arr, low + 1, end);
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     //int* arr = (int*)malloc(sizeof(int) * n);
//     int arr[10000000];
//     for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
//     quickSort(arr, 0, n - 1);
//     for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
// }

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr,arr+n);
    for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
}