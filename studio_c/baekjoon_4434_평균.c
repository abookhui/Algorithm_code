#include<stdio.h>
int main(void) {
	int c, n;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		int arr[1000] = { 0, };
		int cnt = 0, sum = 0; double aver;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {  //arr ÃÊ±âÈ­
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		aver = sum / n;
		for (int k = 0; k < n; k++) {
			if (aver < arr[k])
				cnt++;
		}
		printf("%.3f%%\n", (float)cnt / n * 100);
	}
}