/*
	1541 잃어버린 괄호
	-이 나오면 그 뒤를 () 하기
*/

#include<iostream>
#include<string>

using namespace std;

string op;
string s = "";
int num = 0;
bool mi = false;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> op;

	for (int i = 0; i <= op.size(); i++) {

		if (op[i] == '+' || op[i] == '-' || op[i] == '\0') {
			if (mi) {
				num -= stoi(s);

			}

			else {
				num += stoi(s);
			}

			if (op[i] == '-')
				mi = true;

			s = "";
			continue;
		}
		s += op[i];

	}

	cout << num;
}