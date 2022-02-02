#include<stdio.h>

int arr[100000];
int p_arr[100000] = { 0 };

int main() {

	int n, m;  int a, b, sum = 0, result;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		p_arr[i] = sum;
	}

	while (m-- > 0) {
		scanf("%d %d", &a, &b);
		result = p_arr[b] - p_arr[a - 1];
		printf("%d\n", result);
	}

}