#include<stdio.h>
int main() {
	int n, k; int result = 1;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < k; i++) {
		result *= (n - i);
	}
	for (int i = 1; i <= k; i++) {
		result /= i;
	}
	printf("%d", result);
}