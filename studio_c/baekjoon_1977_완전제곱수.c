#include<stdio.h>
#include<math.h>
int main() {
	int m, n; int sum = 0, ff = -1, min = 1000000000;
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++) {
		if (i % (int)sqrt(i) == 0 && i / (int)sqrt(i) == (int)sqrt(i)) {
			sum += i;
			if (min > i) {
				min = i;
			}
		}
	}
	if (sum == 0) {
		printf("%d\n", ff);
	}
	else {
		printf("%d\n", sum);
		printf("%d\n", min);
	}
}