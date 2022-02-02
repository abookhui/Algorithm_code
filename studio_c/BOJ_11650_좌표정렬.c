#include<stdio.h>
#include<stdlib.h>

typedef struct {    // x좌표와	y좌표를 같이 저장하는 Pair 구조체 만들기
	int x;
	int y;
}Pair;

int compare(const void* a, const void* b);   // 비교함수 정의

int main() {
	int n;
	scanf("%d", &n);

	Pair* arr = (Pair*)malloc(sizeof(Pair) * n); // 동적할당


	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);   // 좌표 저장
	}


	qsort(arr, n, sizeof(Pair), compare);    // 정렬


	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}

	free(arr);
}
int compare(const void* a, const void* b)
{
	Pair* A = (Pair*)a;
	Pair* B = (Pair*)b;

	if (A->x < B->x)
		return -1;
	else if (A->x > B->x)
		return 1;
	else
	{
		if (A->y < B->y)
			return -1;
		else
			return 1;
	}
	return 0;
}
