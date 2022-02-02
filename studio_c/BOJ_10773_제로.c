#include<stdio.h>

int stack[100001];
int cnt = 0;

int pop(int a) {
	if (a != 0) {
		stack[cnt] = a;
		cnt++;
	}
	else {
		cnt--;
		stack[cnt] = 0;
	}
}

int main() {

	int n, a;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		pop(a);

	}
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += stack[i];
	}
	printf("%d", sum);
}