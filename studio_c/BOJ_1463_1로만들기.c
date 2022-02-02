// 1463번

#include<stdio.h>

int check(int a, int b);

int dp[1000000];

int main() {

	int n; scanf("%d", &n);

	for (int i = 2; i <= n; i++) {  // n이 1이면 최소 횟수 0이니 제외
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) {
			dp[i] = check(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0) {
			dp[i] = check(dp[i], dp[i / 3] + 1);
		}
	}
	printf("%d\n", dp[n]);
}

int check(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;

	//return (a < b ? a : b);
}

