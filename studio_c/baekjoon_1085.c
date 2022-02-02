#include<stdio.h>
int xline(int x, int w);
int yline(int y, int h);
int main() {
	int x, y, w, h; int arr[4] = { 0, }; int min = 100000000;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	arr[0] = xline(x, 0); arr[1] = xline(x, w);
	arr[2] = yline(y, h); arr[3] = yline(y, 0);
	for (int i = 0; i < 4; i++) {
		if (min > arr[i])
			min = arr[i];
	}
	printf("%d\n", min);
	return 0;
}
int xline(int x, int w) {
	int sum;
	sum = x - w;
	if (sum < 0)
		sum = sum * (-1);
	return sum;
}
int yline(int y, int h) {
	int sum;
	sum = y - h;
	if (sum < 0)
		sum = sum * (-1);
	return sum;
}