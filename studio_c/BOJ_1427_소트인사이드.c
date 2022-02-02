#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b);

int main() {
	int n; int num[11]; int cnt = 0;

	scanf("%d", &n);

	for (int i = 0; n > 0; i++) {
		num[i] = n % 10;
		cnt++;
		n /= 10;
	}

	qsort(num, cnt, sizeof(int), compare);

	for (int i = 0; i < cnt; i++) {

		printf("%d", num[i]);
	}

}

int compare(const void* a, const void* b) {

	return *(int*)b - *(int*)a;
}