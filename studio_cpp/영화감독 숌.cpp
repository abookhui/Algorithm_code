#include<iostream>
#include<string>

using namespace std;

int main() {

	int n;
	int cnt = 0; string s;
	cin >> n;

	int num = 665;

	while (1) {
		num++;
		s = to_string(num);

		if (s.find("666") != -1) {
			cnt++;
		}

		if (cnt == n) {
			cout << num << '\n';
			break;
		}

	}
}