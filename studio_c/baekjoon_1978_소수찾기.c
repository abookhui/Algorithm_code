#include<stdio.h>
int main() {
	int N, a, n1 = 0, n2 = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a);
		for (int j = 1; j <= a; j++) {
			if (a % j == 0)
				n1++;
		}
		if (n1 == 2) {
			n2++;
			n1 = 0;
		}
		else
			n1 = 0;
	}
	printf("%d", n2);
}


#include<iostream>	

using namespace std;

int arr[100];

int checking(int num) {
	int result = 1;
	if (num == 1)
		return 0;
	else {
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				result = 0;
				break;
			}
		}
	}
	return result;
}
int main() {

	int test, cnt = 0;;
	cin >> test;

	for (int i = 0; i < test; i++) {
		cin >> arr[i];
		if (checking(arr[i]) == 1) {
			cnt += 1;
		}
	}
	cout << cnt << endl;

}