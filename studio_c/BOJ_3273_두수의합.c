#include<stdio.h>
#include<stdlib.h>

int arr[100000];

int cmp(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;

	return n1 - n2;
}

int main() {

	int n, m;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &m);

	qsort(arr, n, sizeof(int), cmp);

	int l = 0, r = n - 1, sum = 0, cnt = 0;

	while (l < r) {

		sum = arr[l] + arr[r];

		if (sum == m) {
			l++; r--;
			cnt++;
		}
		else if (sum < m) {
			l++;
		}
		else
			r--;
	}

	printf("%d", cnt);

}