#include<iostream>
#include<vector>
#include<queue>
#define inf 1e9
using namespace std;

int n, m, s, e;
vector<pair<int, int>>v[1001];
int d[1001];
int city[1001];
vector<int>ans;

void input() {
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> s >> e;

	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}
	
}	

void dijkstra() {
	priority_queue<pair<int, int>>q;
	q.push({ 0,s });
	d[s] = 0;

	while (!q.empty()) {
		int dist = q.top().first;
		int now = q.top().second;
		q.pop();

		if (d[now] < dist) continue;

		for (int i = 0; i < v[now].size(); i++) {
			int nn = v[now][i].first;
			int cost = dist + v[now][i].second;

			if (cost < d[nn]) {
				d[nn] = cost;
				q.push({ cost,nn });
				city[nn] = now;
			}
		}
	}
}

void solve() {
	input();
	dijkstra();

	cout << d[e] << "\n";
	int tmp = e;
	while (tmp) {
		ans.push_back(tmp);
		tmp = city[tmp];
	}
	cout << ans.size() << "\n";

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solve();
	return 0;
}