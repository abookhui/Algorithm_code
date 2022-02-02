// 9095 1,2,3 ¥ı«œ±‚

#include<iostream>

using namespace std;

int dp[11] = { 0,1,2,4 };

int main() {

	int t, n;
	cin >> t;


	for (int i = 4; i < 11; i++) {

		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

}