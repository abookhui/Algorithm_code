#include<iostream>
#include<vector>
#include<queue>
#define inf 1e9
using namespace std;

int n, m;
vector<pair<int, int>>v[50001];
int d[50001];

void input() {
	cin >> n >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}
}

void dijkstra() {
	priority_queue<pair<int, int>> q;
	q.push({ 0,1 });
	d[1] = 0;

	while (!q.empty()) {
		int dist = -q.top().first;
		int now = q.top().second;
		q.pop();

		if (d[now] < dist) continue;

		for (int i = 0; i < v[now].size(); i++) {
			int cost = dist + v[now][i].second;
			int n_now = v[now][i].first;

			if (cost < d[n_now]) {
				d[n_now] = cost;
				q.push({ -cost,n_now });
			}
		}
	}

	cout << d[n] << "\n";
}

void solve() {
	input();
	dijkstra();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solve();
	return 0;
}