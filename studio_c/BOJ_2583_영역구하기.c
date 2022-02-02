#include<stdio.h>
#include<stdlib.h>

int n, m, k;
int x1, x2, y1, y2;
int map[101][101] = { 0, };
int ans[10000] = { 0, };
int idx = 0, cnt;

int dfs(int a, int b) {  //세로 가로
	map[a][b] = 1;

	if (map[a + 1][b] == 0 && a + 1 < m) {
		dfs(a + 1, b);
	}

	if (map[a - 1][b] == 0 && a - 1 >= 0) {
		dfs(a - 1, b);
	}

	if (map[a][b + 1] == 0 && b + 1 < n) {
		dfs(a, b + 1);
	}

	if (map[a][b - 1] == 0 && b - 1 >= 0) {
		dfs(a, b - 1);
	}
	cnt++;

	return cnt;
}

int cmp(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;

	return n1 - n2;
}

int main() {

	scanf("%d %d %d", &m, &n, &k);

	while (k-- > 0) {

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				map[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				cnt = 0;
				ans[idx++] = dfs(i, j);
			}

		}
	}

	qsort(ans, idx, sizeof(int), cmp);
	printf("%d\n", idx);

	for (int i = 0; i < idx; i++) {
		printf("%d ", ans[i]);
	}
}
