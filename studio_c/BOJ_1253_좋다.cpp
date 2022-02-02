/* 투 포인터 이용할 듯
*
	일단 정렬 = 오름차순으로 =

	이분탐색하는데 조건은  l<r = 두 수가 같으면 안되니

	만약 두수를 더한 값과 배열의 어떻 값이 같으먄 l과 r의 ㅇ
	인덱스가 같은지 확인

	그렇지 않으면 cnt 같으면 l++ r--;


*/

#include<iostream>
#include<algorithm>

using namespace std;

int arr[2001];

int main() {

	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		int val = arr[i];  // 찾을 값

		int l = 0, r = n - 1, sum = 0;

		while (l < r) {
			sum = arr[l] + arr[r];

			if (sum == val) {
				if ((l != i) && (r != i)) {
					cnt++;
					break;
				}

				else if (l == i)
					l++;
				else if (r == i)
					r--;
			}

			else if (sum < val)
				l++;

			else
				r--;

		}
	}

	cout << cnt << '\n';

}