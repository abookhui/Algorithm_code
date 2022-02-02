#include<iostream>

using namespace std;

int map[130][130] = { 0, };
int cnt[2] = { 0, };  // 1 0

void cut_paper(int x, int y, int n) {
	int tmp = 0;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (map[i][j] == 1) {
				tmp++;
			}
		}
	}
	if (tmp == 0) {
		cnt[1]++;
	}
	else if (tmp == n * n) {
		cnt[0]++;
	}
	else {
		cut_paper(x, y, n / 2);
		cut_paper(x, y + n / 2, n / 2);
		cut_paper(x + n / 2, y, n / 2);
		cut_paper(x + n / 2, y + n / 2, n / 2);
	}
}
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cut_paper(0, 0, n);

	cout << cnt[1] << '\n' << cnt[0];
}