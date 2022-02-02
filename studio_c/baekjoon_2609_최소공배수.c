#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int random(int min, int max);

int main() {
	int min, max; int n;
	printf("최솟값을 입력하시오\n"); scanf("%d", &min);
	printf("최댓값을 입력하시오\n"); scanf("%d", &max);

	n = random(min, max);
	printf("%d", n);

}
int random(int min, int max) {
	srand((unsigned)time(NULL));
	return (rand() % (max - min) + min);

}
