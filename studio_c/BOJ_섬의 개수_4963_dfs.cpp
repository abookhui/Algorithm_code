#include<iostream>
#include<string.h>

using namespace std;

int map[50][50];
int w, h; // 너비 높이  == 가로 세로

void dfs(int x, int y) { // 세로 가로

	map[x][y] = 0;  //방문 제거

	if (map[x - 1][y - 1] == 1 && x - 1 >= 0 && y - 1 >= 0)  //북서
		dfs(x - 1, y - 1);

	if (map[x - 1][y + 1] == 1 && x - 1 >= 0 && y + 1 < w)   //북동
		dfs(x - 1, y + 1);

	if (map[x + 1][y - 1] == 1 && x + 1 < h && y - 1 >= 0)  // 남서
		dfs(x + 1, y - 1);

	if (map[x + 1][y + 1] == 1 && x + 1 < h && y + 1 < w)   //남동
		dfs(x + 1, y + 1);

	if (map[x][y + 1] == 1 && y + 1 < w)   // 동
		dfs(x, y + 1);

	if (map[x][y - 1] == 1 && y - 1 >= 0)   // 서
		dfs(x, y - 1);

	if (map[x - 1][y] == 1 && x - 1 >= 0)  // 남
		dfs(x - 1, y);

	if (map[x + 1][y] == 1 && x + 1 < h)  // 북
		dfs(x + 1, y);

}
int main() {


	while (1) {
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		memset(map, 0, sizeof(map));

		for (int i = 0; i < h; i++) {  // 세로
			for (int j = 0; j < w; j++) {  //가로
				cin >> map[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {  // 세로
			for (int j = 0; j < w; j++) {  //가로
				if (map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';

	}

}