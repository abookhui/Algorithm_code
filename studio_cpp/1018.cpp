#include<iostream>

using namespace std;

string wb[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};

string bw[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};

string arr[51];

int cnt_w(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[x + i][y + j] != wb[i][j])
				cnt++;
		}
	}

	return cnt;
}

int cnt_b(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[x + i][y + j] != bw[i][j])
				cnt++;
		}
	}

	return cnt;
}

int main() {

	int n, m;
	int min_val = 1000000;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i + 8 <= n; i++) {
		for (int j = 0; j + 8 <= m; j++) {

			int tmp = min(cnt_w(i, j), cnt_b(i, j));

			if (tmp < min_val) {
				min_val = tmp;
			}
		}
	}
	cout << min_val;
}