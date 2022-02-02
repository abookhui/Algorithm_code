#include<stdio.h>
int main() {
	int n; int arr[5];
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		int cnt = 0, t = 0;
		for (int i = 0; n > 0; i++) {
			arr[i] = n % 10;
			n /= 10;
			t++;
			
		}
		
		for (int i = 0; i < t; i++) {
			if (arr[i] == arr[t - (1 + i)])
				cnt++;
		}		
		if (cnt == t)
			printf("yes\n");
		else
			printf("no\n");
	}
}