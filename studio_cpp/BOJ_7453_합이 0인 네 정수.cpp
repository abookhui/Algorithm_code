/*
	7453 합이 0인 네 정수
*/

#include<iostream>
#include<algorithm>
#define Max 4000

using namespace std;

int arr[Max][4];
int sum1[Max * Max];
int sum2[Max * Max];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];

	}

	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum1[idx] = arr[i][0] + arr[j][1];
			sum2[idx] = arr[i][2] + arr[j][3];
			idx++;
		}
	}

	sort(sum1, sum1 + idx);
	sort(sum2, sum2 + idx);

	int lo = 0, ro = idx - 1;
	long long ans = 0;

	while (lo < idx && ro >= 0) {

		if (sum1[lo] + sum2[ro] == 0) {

			long long num1 = 0, num2 = 0;
			int tmp = sum1[lo];

			while (tmp == sum1[lo] && lo < idx) {
				num1++;
				lo++;
			}
			while (tmp + sum2[ro] == 0 && ro >= 0) {
				num2++;
				ro--;
			}

			ans += num1 * num2;

		}
		else if (sum1[lo] + sum2[ro] < 0) {
			lo++;
		}
		else {
			ro--;
		}
	}

	cout << ans << "\n";
}