/* 2468 안전 영역

	max=1; if(max<cnt) max=cnt;

	입력할때 높이 가장큰에까지 반복시키며 cnt가장 큰걸 max_high에 저장

	max_high 만큼 반복해 그중 가장 큰 수를  max 저장 후 출력

	궅
*/

#include<stdio.h>
#include<string.h>

int map[101][101];
int visited[101][101];
int n;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void dfs(int flood, int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny<n && map[nx][ny]>flood && !visited[nx][ny]) {
			dfs(flood, nx, ny);
		}
	}
}

int cmp(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;

	return n1 - n2;
}

int main() {

	scanf("%d", &n);

	int max_high = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);

			if (max_high < map[i][j])
				max_high = map[i][j];

		}
	}

	int max = 1;
	for (int t = 1; t < max_high; t++) {
		memset(visited, 0, sizeof(visited));
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > t && !visited[i][j]) {
					dfs(t, i, j);
					cnt++;
				}
			}
		}
		if (max < cnt) {
			max = cnt;
		}
	}

	printf("%d\n", max);

}