#include<iostream>
#define Max 500001

using namespace std;

int n;
int arr[Max], tmp[Max];
long long ans = 0;

void copy_arr(int start, int end) {

	for (int idx = start; idx <= end; idx++) {
		arr[idx] = tmp[idx];
	}
}

void merge(int low, int mid, int hi) {

	int i = low, k = low;
	int j = mid + 1;
	int cnt = 0;

	while (i <= mid && j <= hi) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
			ans += (long long)cnt;
		}
		else {
			tmp[k++] = arr[j++];
			cnt++;
		}
	}

	if (i > mid) {

		while (j <= hi) {
			tmp[k++] = arr[j++];
			cnt++;
		}
	}
	else {
		while (i <= mid) {
			tmp[k++] = arr[i++];
			ans += (long long)cnt;
		}
	}

	copy_arr(low, hi);
}

void mergesort(int low, int hi) {
	if (low < hi) {
		int mid = (low + hi) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, hi);
		merge(low, mid, hi);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	mergesort(0, n - 1);
	cout << ans << '\n';

}