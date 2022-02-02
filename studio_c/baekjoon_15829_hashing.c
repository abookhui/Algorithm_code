#include<stdio.h>
#include<math.h>
int main() {
	int n; char aph[50]; int sum = 0;
	scanf("%d", &n); scanf("%s", aph);
	for (int i = 0; i < n; i++) {
		sum += (aph[i] - 96) * (int)pow(31, (int)i);
	}
	printf("%d", sum);
}