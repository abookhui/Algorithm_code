/* 자기 보다 큰 사람이 앞에 X 현제 자리가 0 이먄
 그 자리에 사람을 넣는다

 배열이 0인 자리는 자신보다 큰 사람이 차지함

 그러니 자기 보다 큰 사람 수를 줄여 다시 반복

 입력한 left에서 키 큰 사람의 수를 세어 자신보다 큰 사람이 없고 빈 자리가 새긴 경우 그자리에
 줄을 서자
*/

#include<stdio.h>

int main() {

	int n;
	int arr[11] = { 0, };  // 출력할 선 줄

	scanf("%d", &n);

	int left;
	for (int i = 1; i <= n; i++) {

		scanf("%d", &left);

		for (int j = 1; j <= n; j++) {
			if (left == 0 && arr[j] == 0) {
				arr[j] = i;
				break;
			}
			else if (arr[j] == 0) {
				left--;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
}