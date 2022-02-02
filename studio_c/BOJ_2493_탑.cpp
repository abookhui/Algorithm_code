#include<iostream>
#include<stack>
#include<utility>
#define max 500001

using namespace std;

int arr[max];
int ans[max];

int main() {
	int n;
	cin >> n;

	stack<pair<int, int>>s;

	for (int i = 1; i <= n; i++) {  // ют╥б
		cin >> arr[i];
	}

	for (int i = n; i > 0; i--) {
		if (s.empty()) {
			s.push({ arr[i], i });
		}

		else {
			while (s.top().first < arr[i]) {
				ans[s.top().second] = i;
				s.pop();
				if (s.empty())
					break;
			}
			s.push({ arr[i],i });
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}