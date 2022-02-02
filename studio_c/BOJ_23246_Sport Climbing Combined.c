#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int a;
	int b;
	int c;
}player;

player arr[100];
int n;

int mult(int x, int y, int z) {
	int ans = 1;
	int m[3] = { x,y,z };
	for (int i = 0; i < 3; i++) {
		ans *= m[i];
	}
	return ans;
}

int plu(int x, int y, int z) {
	int ans = 1;
	int m[3] = { x,y,z };
	for (int i = 0; i < 3; i++) {
		ans += m[i];
	}
	return ans;
}

int cmp(const void* a, const void* b) {
	player n1 = *(player*)a;
	player n2 = *(player*)b;

	if (n1.b > n2.b) {
		return 1;
	}
	else if (n1.b == n2.b) {
		if (n1.c == n2.c) {
			return n1.a - n2.a;
		}
		return n1.c > n2.c ? 1 : -1;
	}
	return -1;
}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d %d %d %d", &arr[i].a, &x, &y, &z);
		arr[i].b = mult(x, y, z);
		arr[i].c = plu(x, y, z);
	}

	qsort(arr, n, sizeof(player), cmp);

	printf("%d %d %d\n", arr[0].a, arr[1].a, arr[2].a);

}