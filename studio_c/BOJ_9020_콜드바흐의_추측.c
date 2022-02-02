#include<stdio.h>
#include<math.h>
#define size 10000
int num[size] = { 0, };
int main() {

	int test, n;

	for (int i = 2; i < (int)sqrt(size); i++) {
		for (int j = i * i; j <= size; j += i) {
			if (num[j] % i == 0) {
				num[j] = 1;
			}
		}
	}

	scanf("%d", &test);

	for (int i = 0; i < test; i++) {
		scanf("%d", &n);

		for (int j = n / 2; j > 0; j--) {
			if (num[j] != 1 && num[n - j] != 1) {
				printf("%d %d\n", j, n - j);
				break;
			}
		}
	}
}

//c++

#include<iostream>	

using namespace std;


bool chk(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
			break;
		}
	}
	return true;
}

int main() {

	int test, n;

	cin >> test;

	for (int i = 0; i < test; i++) {
		cin >> n;

		for (int j = n / 2; j > 0; j--) {
			if (chk(j) && chk(n - j)) {
				cout << j << ' ' << n - j << endl;
				break;
			}
		}
	}
}