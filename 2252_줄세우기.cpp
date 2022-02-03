#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
vector<int> v[32001];
int visit[32001];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		visit[b]++;
	}
}

void bfs() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int val = q.front();
		q.pop();

		for (int i = 0; i < v[val].size(); i++) {
			visit[v[val][i]]--;
			if (visit[v[val][i]] == 0) q.push(v[val][i]);
		}
		printf("%d ", val);
	}
}

void solve() {
	input();
	bfs();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}