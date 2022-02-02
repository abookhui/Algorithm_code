#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[10000];
int cnt = 0;

int main() {

	int n, m;
	int left = 0, right = 0, sum = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	while (right <= n) {
		if (sum < m) {
			sum += arr[right++];
		}
		else if (sum >= m) {
			sum -= arr[left++];
		}
		if (sum == m) {
			cnt++;
		}
	}

	cout << cnt << endl;
}