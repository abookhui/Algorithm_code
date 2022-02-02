#include<stdio.h>	
#include<stdlib.h>

int arr[100000];
int result[2];


int compare(const void* a, const void* b);

int main() {

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);

	int min = 2000000000; int num;

	for (int i = 0; i < n - 1; i++) {
		num = arr[i] + arr[i + 1];
		if (num < 0) {
			num *= (-1);
		}
		if (min > num) {

			min = num;
			result[0] = arr[i];
			result[1] = arr[i + 1];
		}
	}

	if (result[0] > result[1]) {
		printf("%d %d\n", result[1], result[0]);
	}
	else {
		printf("%d %d\n", result[0], result[1]);
	}

}

int compare(const void* a, const void* b) {

	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (abs(num1) < abs(num2))
		return -1;

	else if (abs(num1) > abs(num2))
		return 1;

	else
		return 0;
}

