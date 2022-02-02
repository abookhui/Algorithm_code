#include<iostream>
#include<cstring>
#include<cmath>

#define S 200001

using namespace std;

int n;
char binary[S * 4] = "1001";
long long input_arr[S];
char num[S * 4];
char ans[S * 4];

void XOR(int a) {
	for (int i = 0; i <= pow(2, a); i++) {
		if (binary[i] == '0') {
			num[i] = '1';
		}
		else if (binary[i] == '1') {
			num[i] = '0';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	long long max_val = 0;
	for (int i = 0; i < n; i++) {
		cin >> input_arr[i];
		if (max_val < input_arr[i]) {
			max_val = input_arr[i];
		}
	}

	int idx = 0;
	while (max_val) {
		max_val /= 2;
		idx++;
	}

	for (int i = 3; i <= idx; i++) {
		strcpy(num, binary);
		XOR(i);
		strcat(binary, num);
	}

	for (int i = 0; i < n; i++) {
		if(input_arr[i])
		ans[i] = binary[input_arr[i] - 1];
	}
	cout << ans << '\n';

}