/*
* \#1389 케빈 베이컨의 6단계 법칙
*
test_case
5 5
1 3
1 4
4 5
4 3
3 2

*/

#include<iostream>
#include<queue>

using namespace std;

int n, m;
int map[101][101] = { 0, };
int visited[101];
queue<int> q;

int min_s = 100000000, ans;

void change() {
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}

void bfs(int num) {
	visited[num] = 1;
	q.push(num);

	while (!q.empty()) {
		num = q.front();

		q.pop();

		for (int i = 1; i <= n; i++) {
			if (map[num][i] == 1 && visited[i] == 0) {
				visited[i] = visited[num] + 1;
				q.push(i);

			}
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		change();

		bfs(i);

		int sum = 0;

		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;

			else {
				sum += (visited[j] - 1);
			}
		}

		if (min_s > sum) {
			min_s = sum;
			ans = i;
		}
	}
	cout << ans;
}