#include<stdio.h>
int fun1() {

	int n; int cnt = 0;
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
	}
	else{
	for (int i = 0; n > 0; i++) {
		n -= 6 * i;
		cnt++;
	}	
	printf("%d\n", cnt);
	}
}
int fun2(void) {
	int n, i = 2, j = 5, cnt = 2;
	scanf("%d", &n);
	if (n == 1) {
		printf("%d", 1);
		return 0;
	}
	while (1) {
		if (i <= n && i + j >= n) {
			printf("%d", cnt);
			break;
		}
		i = i + j + 1;
		j += 6;
		cnt++;
	}
}
int main() {
	while (1) {
		int s; scanf("%d", &s);
		if (s == 0)
			fun1();
		else if (s == 1)
			fun2();
		else
			break;
	}
}