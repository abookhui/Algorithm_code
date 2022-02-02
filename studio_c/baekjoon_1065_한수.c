#include<stdio.h>
int func(int n);
int main(void) {
	int n;

	scanf("%d", &n);

	func(n);



}
int func(int n) {
	int cnt = 0;
	if (n < 100)
		printf("%d", n);
	else {
		cnt = 99; int a, b, c;
		for (int i = 100; i <= n; i++) {
			a = i / 100;
			b = i / 10 % 10;
			c = i % 10;
			if ((b - c) == (a - b))
				cnt++;
		}
		printf("%d", cnt);
	}


}
