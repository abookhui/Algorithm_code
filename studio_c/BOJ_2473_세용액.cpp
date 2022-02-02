#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>  // 자료형에 따른 최소,최대의 값을 표현가능 

using namespace std;

long long arr[5001];
long long sum;
int idx1, idx2, idx3;

int main() {

	int n;

	cin >> n;

	long long num;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	long long min = LLONG_MAX;

	for (int i = 0; i < n; i++) {
		int l = i + 1;
		int r = n - 1;

		while (l < r) {

			sum = arr[i] + arr[l] + arr[r];

			if (abs(sum) < min) {
				min = abs(sum);

				idx1 = i;
				idx2 = l;
				idx3 = r;
			}

			if (sum < 0) {
				l++;
			}

			else {
				r--;
			}
		}
	}

	cout << arr[idx1] << " " << arr[idx2] << " " << arr[idx3] << endl;

}