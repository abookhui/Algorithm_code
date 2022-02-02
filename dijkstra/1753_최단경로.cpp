#include<iostream>
#include<vector>
#include<queue>
#define inf 1e9
using namespace std;

int V, E, k;
vector<pair<int, int>>vec[20001];
int d[20001];

void input() {
	cin >> V >> E;
	cin >> k;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({ v,w });
	}

	for (int i = 1; i <= V; i++) {
		d[i] = inf;
	}
}

void dijkstra() {
	priority_queue<pair<int, int>>q;
	q.push({ 0,k });
	d[k] = 0;

	while (!q.empty()) {
		int dist = -q.top().first;
		int now = q.top().second;
		q.pop();

		//if (d[now] < dist) continue;

		for (int i = 0; i < vec[now].size(); i++) {
			int nn = vec[now][i].first;
			int cost = dist + vec[now][i].second;

			if (cost < d[nn]) {
				d[nn] = cost;
				q.push({ -cost,nn });
			}
		}
	}
}

void solve() {
	input();
	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (d[i] == inf) printf("INF\n");
		else printf("%d\n", d[i]);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solve();
	return 0;
}