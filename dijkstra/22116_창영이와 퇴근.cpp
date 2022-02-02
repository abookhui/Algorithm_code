#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define Max 1001
using namespace std;

int n;
long long map[Max][Max];
long long d[Max][Max];
long long ans = 0, start;
int dr[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool END = false;

void input() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	if (n == 1) {
		cout << 0 << "\n";
		END = true;
	}

	memset(d, Max, sizeof(d));
	start = d[0][0];
	d[0][0] = 0;

}

void dijkstra() {
	priority_queue<pair<long long int, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> q;
	q.push({ abs(map[0][0] - map[0][1]),{0,1} });
	q.push({ abs(map[0][0] - map[1][0]),{1,0} });
	
	while (!q.empty()) {
		long long slope = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();

		if (d[x][y] != start) continue;
		d[x][y] = slope;
		
		ans = max(ans, slope);
		if (x == n - 1 && y == n - 1) break;

		for (int i = 0; i < 4; i++) {
			int nx = x + dr[i][0];
			int ny = y + dr[i][1];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (d[nx][ny] == start) {
				q.push({ abs(map[x][y] - map[nx][ny]),{nx,ny} });
			}
		}
		
	}
	cout << ans << '\n';
}

void solve() {
	input();
	if (END) return;
	dijkstra();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}

