#include<stdio.h>
int main() {
	int arr[8]; int n = 1, m = 1;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 8; i++) {
		if (arr[i] != i + 1) {
			n = 0; break;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (arr[i] != 8 - i) {
			m = 0; break;
		}
	}
	if (n == 1)
		printf("ascending\n");
	if (m == 1)
		printf("descending\n");
	if (n == 0 && m == 0)
		printf("mixed\n");
}