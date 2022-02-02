/*
	mitm # 2~~~ 세 수의 합
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[1001];
vector<int>arr2;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int val = arr[i] + arr[j];
			arr2.push_back(val);
		}
	}

	sort(arr2.begin(), arr2.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int val = arr[j] - arr[i];
			if (binary_search(arr2.begin(), arr2.end(), val)) {
				if (ans < arr[j]) {
					ans = arr[j];
				}
			}
		}
	}

	cout << ans << '\n';
}