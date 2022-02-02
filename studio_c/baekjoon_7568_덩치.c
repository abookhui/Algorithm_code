#include<stdio.h>

int main(void) {
	int cnt[50] = { 0, }; int x_sum[50], y_sum[50];
	int x, y, n;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		x_sum[i] = x; y_sum[i] = y;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i)
				continue;
			if (x_sum[i] < x_sum[j]) {
				if (y_sum[i] < y_sum[j]) {
					cnt[i]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", cnt[i] + 1);
	}
}