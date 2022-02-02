/*
#11047 µ¿Àü0

test_case
10 4200
1
5
10
50
100
500
1000
5000
10000
50000                       ans : 6
---------------------------------
*/

#include<iostream>

using namespace std;

int mon[11];
int ans = 10000000000;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> mon[i];

		if (k / mon[i] > 0) {
			int num = k;
			int val = 0;

			for (int j = i; j >= 0; j--) {
				if (num / mon[j] == 0) {
					continue;
				}
				val += num / mon[j];
				num %= mon[j];

				if (num == 0) {
					break;
				}
			}
			if (num == 0) {
				ans = min(ans, val);

			}

		}
	}
	cout << ans << '\n';
}
