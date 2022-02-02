#include<stdio.h>
#include<string.h>
int func(char arr[], int len);
int main(void) {
	int n, len, sum = 0; char arr[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr);
		len = strlen(arr);
		sum += func(arr, len);
	}
	printf("%d\n", sum);
}
int func(char a[], int len) {
	int key = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (a[i] == a[j]) {
				key = j - i;
				if (key > 1)
					if (a[j - 1] != a[j])
						return 0;
			}
		}
	}
	return 1;
}

