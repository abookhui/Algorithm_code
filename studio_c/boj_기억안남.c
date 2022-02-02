#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int a;
	int b;

}meeting;

meeting arr[100001];

int cmp(const void* a, const void* b) {
	meeting n1 = *(meeting*)a;
	meeting n2 = *(meeting*)b;

	if (n1.b > n2.b) {
		return 1;
	}
	else if (n1.b == n2.b) {
		return n1.a - n2.a;
	}

	return -1;
}

int main() {
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &arr[i].a, &arr[i].b);
	}

	qsort(arr, t, sizeof(meeting), cmp);


	int cnt = 1;
	int endd = arr[0].b;

	for (int i = 1; i < t; i++) {
		if (arr[i].a >= endd) {
			endd = arr[i].b;
			cnt++;
		}

	}

	printf("%d\n", cnt);
}