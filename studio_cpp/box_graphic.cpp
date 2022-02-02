/*
	test case
	n= 24
	data : 161 160 158 169 162 163 158 160 160 158 160
	165 170 152 160 162 167 168 166 164 158 160 160 159

*/

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int data_arr[100];
int data_size;
int data, sum = 0;

double np(int n, double p) {
	double val = (n * p);
	if (val - (int)val == 0) {  // 정수
		int i = ceil(val);
		if (p == 0.25) {
			printf("%d번째와 %d번째의 평균\n", i, i + 1);
		}
		else if (p == 0.5) {
			printf("%d번째와 %d번째의 평균\n", i, i + 1);
		}
		else if (p == 0.75) {
			printf("%d번째와 %d번째의 평균\n", i, i + 1);
		}

		double ans = ((double)data_arr[i] + (double)data_arr[i + 1]) / 2;
		return ans;
	}
	else {  // 실수
		int i = ceil(val);
		if (p == 0.25) {
			printf("%d번째\n", i);
		}
		else if (p == 0.5) {
			printf("%d번째\n", i);
		}
		else if (p == 0.75) {
			printf("%d번째\n", i);
		}
		return data_arr[i];

	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> data_size;

	int si = 0;
	for (int i = 1; i <= data_size; i++) {
		cin >> data_arr[i];
		sum += data_arr[i];
		si += data_arr[i] * data_arr[i];
	}

	printf("크기(n) : %d\n", data_size);

	sort(data_arr, data_arr + (data_size + 1));

	printf("\n정렬 : ");
	for (int i = 1; i <= data_size; i++) {
		cout << data_arr[i] << " ";
	}
	printf("\n");
	printf("sum : %d\n", sum);
	printf("si : %d\n", si);

	double q1 = np(data_size, 0.25);
	printf("Q1 : %lf\n", q1);
	double Me = np(data_size, 0.5);
	printf("Me : %lf\n", Me);
	double q3 = np(data_size, 0.75);
	printf("Q3 : %lf\n", q3);

	double a = q3 - q1;
	double f_l = q1 + (-1.5) * a;
	double f_u = q3 + (1.5) * a;

	printf("%lf - 1.5 * %lf \n", q1, a);
	for (int i = 1; i <= data_size; i++) {
		if (f_l <= data_arr[i]) {
			printf("fl : %d\n", data_arr[i]);
			break;
		}
	}

	printf("%lf + 1.5 * %lf \n", q3, a);
	for (int i = data_size; i > 0; i--) {
		if (f_u >= data_arr[i]) {
			printf("fu : %d\n", data_arr[i]);
			break;
		}
	}

}