#include<iostream>
#define max 10001

using namespace std;

int n, m;         //정점의 수  ,  간선의 수
int map[max][max];
int visited[max] = { 0, };

void dfs(int node) {
	
	visited[node] = 1;

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0 && map[node][i] == 1) {
			dfs(i);
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) { //  무방향 그래프이니 두 점을 모두 연결해 주는 거임
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;

	}

	int cnt = 0;                // count 해주기
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;
}