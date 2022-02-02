// 1915 가장 큰 정사각형


#include<iostream>

using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];

int solution() {
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i - 1][j - 1] != 0) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	return ans * ans;

}

int main() {

	cin >> n >> m;

	string a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < m; j++) {
			arr[i][j] = a[j] - '0';
		}
	}

	cout << solution() << '\n';

}