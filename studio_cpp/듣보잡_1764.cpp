// µË∫∏¿‚ 1764

#include<iostream>
#include<algorithm>


using namespace std;

string arr[500001];
string arr2[500001];
int main() {

	int n, m;

	string s;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int idx = 0;
	for (int i = 0; i < m; i++) {
		cin >> s;

		if (binary_search(arr, arr + n, s)) {
			arr2[idx] = s;
			idx++;

		}

	}

	cout << idx << '\n';

	sort(arr2, arr2 + idx);

	for (int i = 0; i < idx; i++) {
		cout << arr2[i] << '\n';
	}
}