#include<stdio.h>
int main() {
	int n, n3 = 0; int n1 = 0; int n2 = 1;
	scanf("%d", &n);
	if (n == 0)
		printf("%d\n", n1);
	if (n == 1)
		printf("%d\n", n2);
	for (int i = 2; i <= n; i++) {
		n3 = n1 + n2;
		n1 = n2; n2 = n3;
	}
	if (n >= 2)
		printf("%d", n3);
}