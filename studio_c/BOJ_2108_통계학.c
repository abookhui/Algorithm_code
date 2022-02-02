#include<stdio.h>	
#include<stdlib.h>
#include<math.h>

int arr[500001];
int n;
int cmp(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	return n1 - n2;
}

int mode()
{
	int a[8001] = { 0 };
	int i, idx, max = 0, cnt = 0;

	for (i = 0; i < n; i++)
	{
		idx = arr[i] + 4000;
		a[idx] += 1;

		if (a[idx] > max)
			max = a[idx];
	}

	for (i = 0, idx = 0; i < 8001; i++)
	{
		if (a[i] == 0)
			continue;

		if (a[i] == max)
		{
			if (cnt == 0)
			{
				idx = i;
				cnt += 1;
			}
			else if (cnt == 1)
			{
				idx = i;
				break;
			}
		}
	}
	return idx - 4000;

}

int main() {
	scanf("%d", &n);

	double sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	int average = round(sum / n);
	qsort(arr, n, sizeof(int), cmp);

	printf("%d\n", average);
	printf("%d\n", arr[(n - 1) / 2]);
	printf("%d\n", mode());
	printf("%d\n", arr[n - 1] - arr[0]);

}