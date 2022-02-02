/*
	#1780 종이의 개수

	재귀함수
		1. 만약 종이가 모두 같은 수이면 사용 cnt++;
		2. (1)이 아닌경우 종이의 크기를 9개로 자르고 (1)과정 반복;

	-1, 0 1 만 가능.
*/

#include<iostream>

using namespace std;

int n;
int p[2200][2200];
int cnt[3] = { 0, };

bool chk(int a, int b, int N) {
	int cmp = p[a][b];

	for (int i = a; i < a + N; i++) {
		for (int j = b; j < b + N; j++) {

			if (cmp != p[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void cut_paper(int x, int y, int N) {

	if (chk(x, y, N)) {
		int idx = p[x][y] + 1;
		cnt[idx] += 1;
		return;
	}

	int d = N / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			cut_paper(x + i * d, y + j * d, d);
		}
	}


}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];

		}
	}

	cut_paper(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << '\n';
	}
}