#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k;
vector<int> know;
vector<vector<int>>party;

void input() {
	int a;
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		cin >> a;
		know.push_back(a);
	}

	for (int i = 0; i < m; i++) {
		vector<int> v;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			v.push_back(b);
		}
		party.push_back(v);
	}
}

bool search(int val) {
	for (int i = 0; i < know.size(); i++) {
		if (val == know[i]) {
			return false;
		}
	}
	return true;
}

void func() {
	for (int i = 0; i < m; i++) {
		bool chk = false;
		for (int j = 0; j < party[i].size(); j++) {
			if (!search(party[i][j])) {
				chk = true;
				break;
			}
		}
		if (chk) {
			for (int j = 0; j < party[i].size(); j++) {
				know.push_back(party[i][j]);
			}
		}
	}
	sort(know.begin(), know.end());
	know.erase(unique(know.begin(), know.end()), know.end());
}

void sol() {
	int ans = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			if (search(party[i][j])) {
				ans++;
				break;
			}
		}
	}
	
	cout << ans << '\n';
}

void solve() {
	input();
	for (int i = 0; i < m; i++) func();
	sol();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}