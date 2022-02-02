#include<iostream> 
#include<queue> 
#include<vector> 
#define inf 1000000

using namespace std; 

int n, m, a, b;
vector<pair<int,int>>v[1001];
int dist[1001];

void input() {
	cin >> a >> b >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back({ y,1 });
		v[y].push_back({ x,1 });
	}
	
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
}

void dijkstra() {
	priority_queue<pair<int, int>>q;
	q.push({ 0,a });
	dist[a] = 0;

	while (!q.empty()) {
		int present_node = q.top().second;
		int d = -q.top().first;
		q.pop();

		if (dist[present_node] < d) continue;

		for (int i = 0; i < v[present_node].size(); i++) {
			int cost = d + v[present_node][i].second;

			if (cost < dist[v[present_node][i].first]) {
				dist[v[present_node][i].first] = cost;
				q.push({ -cost,v[present_node][i].first });
			}
		}
	}
}

void solve() {
	input();
	dijkstra();

	if (dist[b] == inf) cout << -1 << "\n";
	else cout << dist[b] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}