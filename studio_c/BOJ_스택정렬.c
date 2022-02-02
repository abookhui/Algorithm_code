#include<stdio.h>
#define size 100000

int stack[size];
char result[size * 2];
int cnt = 0;


int main() {
	int n;
	scanf("%d", &n);

	int arr[size];    // 배열;

	for (int i = 0; i < n; i++) {   // 크기 n의 숫자 배열 입력;
		scanf("%d", &arr[i]);
	}

	int num = 1;
	int index = 0; int result_idx = 0;

	while (1) {
		if (cnt == 0 || stack[cnt] < arr[index]) {

			stack[++cnt] = num++;
			result[result_idx++] = '+';
		}
		else if (stack[cnt] == arr[index]) {
			cnt--;
			result[result_idx++] = '-';
			index++;
		}
		else {
			printf("NO\n");
			return 0;
		}
		if (result_idx == 2 * n)
			break;
	}

	for (int i = 0; i < result_idx; i++) {
		printf("%c\n", result[i]);
	}

}