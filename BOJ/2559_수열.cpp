#include<iostream>
#include<vector>
using namespace std;

int n, k;
int arr[100001];
long long ans;

void input() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void sol() {
	int lo = 0;
	long long sum = 0;
	for (int i = lo; i < lo + k; i++) {
		sum += arr[i];
	}
	ans = sum;

	while (1) {
		if (lo + k >= n) break;

		sum -= arr[lo];
		sum += arr[lo + k];

		ans = max(sum, ans);
		lo++;
	}
	cout << ans << '\n';
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