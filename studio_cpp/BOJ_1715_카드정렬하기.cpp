/*
	1715 카드 정렬하기
*/


#include<iostream>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>>q;
int n;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push(a);
	}

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int val = 0;
		val += q.top();
		q.pop();
		val += q.top();
		q.pop();

		q.push(val);
		ans += val;

		if (q.size() == 1) {
			break;
		}
	}
	cout << ans;
}