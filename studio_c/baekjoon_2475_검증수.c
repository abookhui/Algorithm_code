#include<stdio.h>
int main() {
	int n; int sum = 0; int a;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &n);
		sum += n * n;
	}
	a = sum % 10;
	printf("%d\n", a);
}