#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	return n1 - n2;
}
int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);

	printf("%d\n", arr[m - 1]);
}