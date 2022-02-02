#include<stdio.h>
int main() {
	int a; int sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &a);
			sum += a;
		}if (sum == 0)
			printf("D\n");
		else if (sum == 1)
			printf("C\n");
		else if (sum == 2)
			printf("B\n");
		else if (sum == 3)
			printf("A\n");
		else if (sum == 4)
			printf("E\n");
		sum = 0;
	}
}