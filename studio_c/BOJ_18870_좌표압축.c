#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int num;
	int idx;
}Arr;

int result[1000000];

int compare(const void* a, const void* b) {
	Arr n1 = *(Arr*)a;
	Arr n2 = *(Arr*)b;

	if (n1.num > n2.num)
		return 1;
	else if (n1.num < n2.num)
		return -1;
	return 0;
}

int main() {

	int n, cnt, chk;

	scanf("%d", &n);

	Arr* arr = (Arr*)malloc(sizeof(Arr) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].num);
		arr[i].idx = i;
	}
	qsort(arr, n, sizeof(Arr), compare);

	cnt = 0;
	chk = arr[0].num;

	for (int i = 0; i < n; i++) {
		if (arr[i].num != chk) {
			cnt++;
		}
		result[arr[i].idx] = cnt;
		chk = arr[i].num;

	}

	for (int i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}

	free(arr);
}