#include<iostream>
#include<queue>
#define size 1001

using namespace std;

int grap[size][size];
bool visit[size] = { 0, };

queue<int> q;

int n, m, v;

void DFS(int v) {
	visit[v] = true;

	cout << v << " ";

	for (int i = 1; i <= n; i++) {
		if (grap[v][i] == 1 && visit[i] == 0) {
			DFS(i);
		}

	}
}

void BFS(int v) {

	q.push(v);
	visit[v] = true;

	cout << v << " ";

	while (1) {

		if (q.empty())
			break;

		v = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (grap[v][i] == 1 && visit[i] == 0) {
				q.push(i);
				visit[i] = true;

				cout << i << " ";
			}
		}
	}
}

int main() {

	cin >> n >> m >> v;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		grap[a][b] = 1;
		grap[b][a] = 1;
	}

	DFS(v);
	cout << endl;

	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}

	BFS(v);

}