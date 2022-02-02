#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, a;
priority_queue<int, vector<int>, greater<int>>q1;
priority_queue<int>q2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	while (n-- > 0) {
		cin >> a;

		if (a == 0) {
			if (q1.empty() && q2.empty()) {
				cout << 0 << '\n';
			}
			else if (q1.empty()) {
				cout << q2.top() << '\n';
				q2.pop();
			}
			else if (q2.empty()) {
				cout << q1.top() << "\n";
				q1.pop();
			}
			else {
				if (q1.top() < (-1) * q2.top()) {
					cout << q1.top() << '\n';
					q1.pop();
				}
				else {
					cout << q2.top() << '\n';
					q2.pop();
				}
			}
		}

		else if (a > 0) {
			q1.push(a);
		}
		else {
			q2.push(a);
		}
	}

}