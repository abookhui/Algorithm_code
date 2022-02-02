#include<iostream>
#include<queue>

using namespace std;

int n, m; // col, row
char map[101][101];
int dist[101][101];
bool visited[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int a, int b) {
	queue<pair<int, int>>q;
	visited[a][b] = true;
	q.push({ a,b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && x < n && y < m) {
				if (map[nx][ny] == '1' && visited[nx][ny] == false) {
					dist[nx][ny] = dist[x][y] + 1;
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}


	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	bfs(0, 0);

	cout << dist[n - 1][m - 1] + 1 << '\n';



}