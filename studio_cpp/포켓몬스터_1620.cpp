#include<iostream>
#include<algorithm>
#include<string>
#include<utility>

using namespace std;

pair<string, int>p[100001];
string s;
string p2[100001];
int n, m;

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> p[i].first;
		p[i].second = i;
		p2[i] = p[i].first;
	}


	sort(p, p + n);


	for (int i = 0; i < m; i++) {
		cin >> s;

		if (s[0] >= '0' && s[0] <= '9') {
			int num = stoi(s);
			cout << p2[num] << '\n';
		}

		else {

			int l = 0, r = n - 1;

			while (l <= r) {
				int mid = (l + r) / 2;

				if (p[mid].first == s) {
					cout << p[mid].second << '\n';
					break;
				}

				else if (p[mid].first < s) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}

				if (p[n].first == s) {
					cout << p[n].second << '\n';
					break;
				}
			}
		}
	}
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>

using namespace std;

int n, m;
vector<pair<string, int>> p;
vector<string> p2;
char s[21];

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%s", s);

		p.push_back(make_pair(s, i + 1));
		p2.push_back(s);
	}

	sort(p.begin(), p.end());

	for (int i = 0; i < m; i++) {
		scanf("%s", s);

		if (s[0] >= '0' && s[0] <= '9') {
			int num = stoi(s) - 1;
			cout << p2[num] << '\n';
		}

		else {

			int l = 0, r = n - 1;

			while (l <= r) {
				int mid = (l + r) / 2;

				if (p[mid].first == s) {
					printf("%d\n", p[mid].second);
					break;
				}
				else if (p[mid].first < s) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
		}
	}
	return 0;
}


