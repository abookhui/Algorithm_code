#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<vector<int>> map;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int>v;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		map.push_back(v);
	}
}

void sol() {
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 0; i < n; i++) {
		q.push(map[n - 1][i]);
	}

	for (int i = n - 2; i >= 0; i--) {
		vector<int>v;
		v = map[i];
		sort(v.begin(), v.end());
		for (int j = 0; j < n; j++) {
			if (q.top() < v[j]) {
				q.pop();
				q.push(v[j]);
			}
		}
	}

	cout << q.top() << '\n';
}

void solve() {
	input();
	sol();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	solve();
	return 0;
}
