// 3649 로봇 프로젝트

#include<iostream>
#include<algorithm>

using namespace std;

int x, n;
int arr[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> x) {

		x *= 10000000;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);

		int lo = 0, ro = n - 1;
		int sum = 0;

		while (lo < ro) {
			sum = arr[lo] + arr[ro];

			if (sum == x) {
				break;
			}
			else if (sum < x) {
				lo++;
			}
			else {
				ro--;
			}

		}

		if (sum == x) {
			printf("yes %d %d\n", arr[lo], arr[ro]);
		}

		else {
			printf("danger\n");
		}
	}
}
