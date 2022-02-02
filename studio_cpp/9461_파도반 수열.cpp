// 9461 파도반 수열 

#include<iostream>


using namespace std;

long long dp[101];
int cnt = 0;

long long solution(int n) {
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	for (int i = 6; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	return dp[n];

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case, n;

	cin >> test_case;

	while (test_case-- > 0) {
		cin >> n;
		cout << solution(n) << '\n';

	}
}