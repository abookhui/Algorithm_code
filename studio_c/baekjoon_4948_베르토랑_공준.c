#include <stdio.h> 
int main() {
	int n, cnt = 0;
	int arr[246913] = { 0, };
	arr[0] = 1, arr[1] = 1;
	for (int j = 2; j < 246913 / j; j++) {
		if (arr[j] == 1)
			continue;
		for (int i = j * j; i < 246913; i += j) {
			if (i % j == 0) {
				arr[i] = 1;
			}
		}
	}
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == 0) {
				cnt++;
			}
		}
		printf("%d\n", cnt);	
	}
	return 0;
}