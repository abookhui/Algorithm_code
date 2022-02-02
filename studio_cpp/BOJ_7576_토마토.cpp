#include<iostream>
#include<queue>

using namespace std;

int arr[1001][1001] = { 0, };
queue<pair<int, int>>q;  // 가로 세로
int m, n;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs() {
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[ny][nx] == 0) {
				arr[ny][nx] = arr[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	bfs();

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (arr[i][j] > ans) {
				ans = arr[i][j];
			}
		}
	}

	cout << ans - 1 << '\n';


}