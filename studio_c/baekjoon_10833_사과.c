#include<stdio.h>
int main() {
	int n; scanf("%d", &n);
	int student, apple, rest; int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &student, &apple);
		rest = apple % student;
		sum += rest;
	}
	printf("%d\n", sum);
}