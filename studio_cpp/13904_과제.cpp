// # 13904 °úÁ¦

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>>task;
int arr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, deadline, scores, max_ = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> deadline >> scores;
		task.push_back({ scores,deadline });
		if (max_ < deadline)
			max_ = deadline;

	}

	sort(task.begin(), task.end(), greater < pair<int, int>>());

	for (int i = 0; i < n; i++) {
		int idx = task[i].second;
		while (idx > 0) {
			if (arr[idx] == 0) {
				arr[idx] = task[i].first;
				break;
			}
			else {
				idx--;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= max_; i++) {
		ans += arr[i];
	}

	cout << ans << '\n';
}