#include<iostream>

using namespace std;

int dp[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2 + (dp[i - 1] - dp[i - 2])) % 9901;
	}

	cout << dp[n] << '\n';
}