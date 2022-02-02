#include<stdio.h>
int main() {
	int a, b; int max = 0;
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &a);
		if (max < a) {
			max = a;
			b = i;
		}
	}
	printf("%d\n", max);
	printf("%d\n", b);
}