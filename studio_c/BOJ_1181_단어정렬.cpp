#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main() {

	int n;
	cin >> n;

	vector<string>word(n);


	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}

	sort(word.begin(), word.end(), compare);

	cout << word[0] << endl;
	for (int i = 1; i < n; i++) {
		if (word[i] != word[i - 1]) {
			cout << word[i] << endl;
		}
	}

	return 0;

}