#include<iostream>
#include<vector>
using namespace std;

int n, ans = 0;
int arr[1000001];
int dp[1000001];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void sol() {
	for (int i = 0; i < n; i++) {
		int val = arr[i];
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			if (val > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(dp[i], ans);
	}
	cout << ans << "\n";
}

void solve() {
	input();
	sol();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}