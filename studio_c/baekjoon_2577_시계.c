#include<stdio.h>
#define min 60
int main() {
	int h, m; int M, H;
	scanf("%d %d", &h, &m);
	M = m - 45;
	H = h;
	if (M < 0) {
		M = min + m - 45;
		if (h == 0)
			h = 24;
		H = h - 1;
		
	}
	printf("%d %d", H, M);
}