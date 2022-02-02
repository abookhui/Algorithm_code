#include<stdio.h>
int main() {
	int arr[10]; int a; int chk = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a);
		arr[i] = a % 42;
	}
	for (int i = 0; i < 10; i++) {
			int cnt = 0;

			for (int j = i + 1; j < 10; j++) {
			if (arr[i] == arr[j]) {
				cnt++;
				
			}
		}
		if (cnt == 0) {
			chk++;
		}
	}
	printf("%d", chk);
}
