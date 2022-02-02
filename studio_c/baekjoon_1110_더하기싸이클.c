#include<stdio.h>
int main(void) {
	int n, chk;
	int a, b, c, d;
	int cnt = 0;

	scanf("%d", &n); chk = n;
	while (1) {
		a = n / 10;
		b = n % 10;
		c = (a + b) % 10;
		d = b * 10 + c;
		cnt++;
		n = d;
		if (d == chk)
			break;
	}
	printf("%d", cnt);
}