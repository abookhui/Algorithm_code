#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int ans = 0;
vector<int> arr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int idx = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
		if (a < 0) idx++;
	}

	sort(arr.begin(), arr.end());

	for (int i = n - 1; i >= idx; i -= m) {
		ans += arr[i] * 2;
	}

	for (int i = 0; i < idx; i += m) {
		ans += abs(arr[i]) * 2;
	}

	ans -= max(abs(arr[0]), abs(arr[n - 1]));

	cout << ans << '\n';
}