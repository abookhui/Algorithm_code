//#include<iostream>
//
//using namespace std;
//
//int map[101][101];
//bool visit[101];
//int cnt = -1;
//int node, edge;      // 노드와 간선
//
//void DFS(int n) {
//	visit[n] = true;
//	cnt++;
//	for (int i = 1; i <= node; i++) {
//		if (map[n][i] == 1 && visit[i] == 0) {
//			DFS(i);
//		}
//	}
//
//}
//int main() {
//
//	cin >> node >> edge;
//
//	int a, b;
//
//	for (int i = 0; i < edge; i++) {
//		cin >> a >> b;
//
//		map[a][b] = 1;
//		map[b][a] = 1;
//	}
//
//	DFS(1);
//
//	cout << cnt;
//
//}

#include<iostream>
#include<queue>

using namespace std;

int map[101][101];
bool visit[101];
int cnt = 0;
int node, edge;      // 노드와 간선

queue<int>q;

void BFS(int n) {
	q.push(n);
	visit[n] = true;

	while (!q.empty()) {
		n = q.front();
		q.pop();

		for (int i = 1; i <= node; i++) {
			if (map[n][i] == 1 && visit[i] == 0) {
				q.push(i);
				visit[i] = true;

				cnt++;
			}
		}
	}

}

int main() {

	cin >> node >> edge;

	int a, b;

	for (int i = 0; i < edge; i++) {
		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	BFS(1);

	cout << cnt;

}