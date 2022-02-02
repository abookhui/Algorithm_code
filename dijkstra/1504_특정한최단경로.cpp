#include<iostream>
#include<vector>
#include<queue>
#define inf 1e9
using namespace std;

int n, m, v1, v2;
vector<pair<int, int>>v[801];
int d[801];
int s[4];
int ans[2] = { 0, };

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	s[0] = 1;
	s[3] = n;
	cin >> s[1] >> s[2];
	
}

void init() {
	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}
}

void dijkstra(int start) {
	priority_queue<pair<int, int>>q;
	q.push({ 0,start });
	d[start] = 0;

	while (!q.empty()) {
		int dist = -q.top().first;
		int node = q.top().second;
		q.pop();

		if (d[node] < dist) continue;

		for (int i = 0; i < v[node].size(); i++) {
			int cost = dist + v[node][i].second;
			int next_node = v[node][i].first;

			if (d[next_node] > cost) {
				d[next_node] = cost;
				q.push({ -cost,next_node });
			}
		}
	}
}

void sol(int idx) {
	for (int i = 0; i < 3; i++) {
		init();
		dijkstra(s[i]);
		if (d[s[i + 1]] == inf) {
			ans[idx] = -1;
			break;
		}
		//printf("%d\n", d[s[i+1]]);
		ans[idx] += d[s[i + 1]];
	}
}

void solve() {
	int answer;
	input();
	sol(0);
	swap(s[1], s[2]);
	sol(1);

	answer = min(ans[0], ans[1]);
	if (answer == -1) printf("-1\n");
	else cout << answer << "\n";
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solve();
	return 0;
}