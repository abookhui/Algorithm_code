#include<stdio.h>
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		for (int k = (n - 1); k > i; k--) {
			printf("*");
		}

		for (int m = n; m > i; m--) {
			printf("*");
		}
		printf("\n");

	}
}