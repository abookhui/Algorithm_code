#include<stdio.h>
#include<string.h>
int main() {
	char arr[1000000]; int len, n = 0, m = 0;
	scanf("%[^\n]", &arr);
	len = strlen(arr);

	for (int j = 0; j < len; j++) {
		if (arr[j] == ' ') {
			m++;
		}
	}
	if (m >= len) {
		printf("0");
	}
	else {
		for (int i = 1; i < len - 1; i++) {
			if (arr[i] == ' ') {
				n++;
			}
		}
		printf("%d", n + 1);
	}
}