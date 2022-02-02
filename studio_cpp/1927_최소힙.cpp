// 11279 ÃÖ¼Ò Èü

#include<iostream>
#include<queue>

using namespace std;

priority_queue<int>q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, a;;

	cin >> n;

	while (n-- > 0) {
		cin >> a;
		a *= (-1);
		if (a == 0) {
			if (q.empty()) {
				cout << 0 << '\n';
			}
			else {
				int ans = q.top() * (-1);
				cout << ans << '\n';
				q.pop();
			}
		}
		else {
			q.push(a);
		}
	}

}