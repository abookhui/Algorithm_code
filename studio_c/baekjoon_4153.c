#include<stdio.h>
#include<math.h>
int main() {
	int arr[3] = { 0, }; int temp; int max = 0;
	while (1) {
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		if (arr[0] == 0 || arr[1] == 0 || arr[2] == 0)
			break;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3 - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		if (pow(arr[2], 2) == pow(arr[0], 2) + pow(arr[1], 2)) {
			printf("right\n");
		}
		else
			printf("wrong\n");
	}
	return 0;
}