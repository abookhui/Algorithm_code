/*
#17626 Four Squares

223^2 == 49729
234^2 == 50176

*/

#include<iostream>	

using namespace std;

int dp[500001];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[1] + dp[i - 1];
		for (int j = 2; j * j <= i; j++) {
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	cout << dp[n];
}