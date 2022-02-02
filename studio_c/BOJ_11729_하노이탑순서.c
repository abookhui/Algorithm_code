#include<stdio.h>
#include<math.h>

void hano(int n, int a, int b, int c);
int main() {

	int n;
	scanf("%d", &n);

	int cnt = pow(2, n);
	printf("%d\n", cnt - 1);

	hano(n, 1, 2, 3);

}
void hano(int n, int a, int b, int c) {

	if (n == 1) {
		printf("%d %d\n", a, c);

	}
	else {

		hano(n - 1, a, c, b);

		printf("%d %d\n", a, c);

		hano(n - 1, b, a, c);
	}
}