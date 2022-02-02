#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<string>map;
bool visited[13][7];

int dr[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int Is_four = 0;

vector<pair<int,int>> v1, v2;

void input() {
	string a;
	for (int i = 0; i < 12; i++) {
		cin >> a;
		map.push_back(a);
	}
}

bool chk(int x, int y,int nx, int ny) {

	if (!(nx >= 0 && ny >= 0 && nx < 12 && ny < 6)) return false;
	if (map[nx][ny] == '.') return false;
	if (visited[nx][ny] == true) return false;
	if (map[x][y] != map[nx][ny]) return false;

	return true;
}	

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dr[i][0];
		int ny = y + dr[i][1];

		if (chk(x, y, nx, ny)) {
			Is_four++;
			visited[nx][ny] = true;
			v1.push_back({ nx,ny });

			dfs(nx, ny);
		}
	}
}

void down_puyo() {

	for (int i = 0; i < v2.size(); i++) {
		int x = v2[i].first;
		int y = v2[i].second;

		map[x][y] = '.';
	}

	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == '.') continue;
			int idx = i;

			while (1) {
				if (idx == 11 || map[idx + 1][j] != '.') break;

				map[idx + 1][j] = map[idx][j];
				map[idx][j] = '.';
				idx++;
			}
		}
	}
}
void sol() {
	bool check = true;
	int ans = 0;

	while (check) {
		check = false;
		memset(visited, false, sizeof(visited));
		v2.clear();

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && !visited[i][j]) {
					Is_four = 1;
					v1.push_back({ i,j });
					visited[i][j] = true;

					dfs(i, j);

					if (Is_four >= 4) {
						check = true;
						for (int i = 0; i < v1.size(); i++) {
							v2.push_back(v1[i]);
						}
					}
					v1.clear();
				}
			}
		}

		down_puyo();

		if (check == true) ans++;
		else check = false;
	}
	cout << ans << '\n';
}

void solve(){
	input();
	sol();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}