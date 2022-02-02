#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define inf 1e9
using namespace std;

int n;
int map[126][126];
int d[126][126];
bool END = false;
int dr[4][2] = { {1,0},{-1,0},{0,1 },{0,-1} };
int ans, t = 1;

void input() {
	cin >> n;
	if (n == 0) {
		END = true;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void init() {
	for (int i = 0; i < 126; i++) {
		for (int j = 0; j < 126; j++) {
			d[i][j] = inf;
		}
	}
}

bool chk(int a, int b) {
	if (a >= 0 && b >= 0 && a < n && b < n) return true;
	return false;
}

void dijkstra() {
	priority_queue<pair<int, int>>q;
	q.push({ 0,0 });
	d[0][0] = map[0][0];

	while (!q.empty()) {
		int x = q.top().first;
		int y = q.top().second;	
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dr[i][0];
			int ny = y + dr[i][1];
			int cost = d[x][y] + map[nx][ny];

			if (chk(nx, ny)) {
				if (d[nx][ny] > cost) {
					d[nx][ny] = cost;
					q.push({ nx,ny });
				}
			}
		}
	}
	ans = d[n - 1][n - 1];
}

void solve() {
	while(1) {
		input();
		if (END) return;
		init();
		//memset(map, 0, sizeof(map));
		dijkstra();
		printf("Problem %d: %d\n", t++ , ans);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}