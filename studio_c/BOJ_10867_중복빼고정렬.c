#include<stdio.h>
#include<stdlib.h>

void overlaption_remove(int* arr, int* len);

int check(int* arr, int arr_size, int val);

int compare(const void* a, const void* b);

int main() {
	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);


	for (int i = 0; i < n; i++) {  // 배열 초기화
		scanf("%d", &arr[i]);
	}

	overlaption_remove(arr, &n); //중복 제거

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	free(arr);
}

void overlaption_remove(int* arr, int* len) {

	int* tmp = (int*)malloc(sizeof(int) * (*len));
	int cnt = 0;

	for (int i = 0; i < (*len); i++) {
		if (check(tmp, cnt, arr[i]) == 0) {
			tmp[cnt] = arr[i];
			cnt++;
		}
	}

	for (int k = 0; k < cnt; k++) { // arr에 tmp넣기
		arr[k] = tmp[k];
	}
	*len = cnt; //길이 바꿔주기

	free(tmp);
}

int check(int* arr, int arr_size, int val) {
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] == val)
			return 1;
	}
	return 0;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
