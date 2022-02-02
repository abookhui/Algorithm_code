/* 주의 할 것

<01> 음수가 존재
	1. 음수가 홀수 일 경우
	절댓값이 큰 두 음수를 곱하고 나머지는 따로 더한다.( 만약 0이 존재한다면 0과 곱해준다.)
	2. 음수 짝수 인 경우
	절댓값이 큰짝끼리 곱해준다.

<02> 1이 존재
	1.n이 홀수이면 1을 제외한 수들끼리 짝을 이루고 1은 더한다.
	2.n이 짝수이면 절댓값이 큰 수끼리 짝을 이루다 1과 나머지 하나는 그냥 더하준다.

<03> 0이 존재
	<01>에서와 같이 음수가 존재할때 유용 만약 음수가 존재하지 않으면 0은 없는 취급
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int>arr_p;
	vector<int>arr_m;
	vector<int>ans;
	int zero = 0;

	int num; int sum;
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num < 0) {
			arr_m.push_back(num);
		}
		if (num > 0) {
			if (num == 1)
				ans.push_back(num);
			else {
				arr_p.push_back(num);
			}
		}
		if (num == 0) {
			zero++;
		}
	}

	sort(arr_p.begin(), arr_p.end());
	sort(arr_m.begin(), arr_m.end(), greater<int>());

	if (arr_p.size() % 2 != 0) {
		ans.push_back(arr_p[0]);
	}

	for (int i = arr_p.size() - 1; i > 0; i -= 2) {  //양수
		sum = arr_p[i] * arr_p[i - 1];
		ans.push_back(sum);
	}



	if (arr_m.size() % 2 != 0) {   // 음수
		if (zero > 0) {
			ans.push_back(arr_m[0] * 0);
		}
		else {
			ans.push_back(arr_m[0]);
		}
	}

	for (int i = arr_m.size() - 1; i > 0; i -= 2) {
		sum = arr_m[i] * arr_m[i - 1];
		ans.push_back(sum);
	}
	int result = 0;
	for (int i = 0; i < ans.size(); i++) {
		result += ans[i];

	}
	cout << result;
}