#include<stdio.h>
int main() {
	int a, b; int sum = 0; int max = -9999;

	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &a, &b);
		sum -= a;
		sum += b;
		if (max < sum) {
			max = sum;
		}
	}
	printf("%d\n", max);
}