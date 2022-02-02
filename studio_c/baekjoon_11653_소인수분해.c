#include<stdio.h>

int main(void) {
	int n; int num;
	int i = 2;
	scanf("%d", &n);
	num = n;
	while (1) {
		if (n == 1 || num == 1)
			break;
		if (n % i != 0) {
			i++;
		}
		else if (n % i == 0) {
			n = n / i;
			printf("%d\n", i);
			i = 2;
		}
	}
}
