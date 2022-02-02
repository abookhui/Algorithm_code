#include<stdio.h>

int main() {
	int a, b, m = 0; scanf("%d %d", &a, &b); int arr[1001] = { 0, }; int sum = 0;
	for (int i = 0; i < b + 1 && m < b; i++) {
		for (int j = 0; j < i && m < b; j++) {

			arr[m] = i;
			
			m++;
		}
	}
	for (int k = a - 1; k < b; k++) {
		sum += arr[k];
	}
	printf("%d\n", sum);
}