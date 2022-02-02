#include <stdio.h>

int main(void) { 
	int n, i, j, sum, add;  
	char arr[81] = { 0, };
	scanf("%d", &n); 
	for(i=0; i<n; i++) {
		sum=0, add=1; 
		scanf("%s", arr); 
		for (j = 0; arr[j] != 0; j++) {
			if(arr[j]=='O') {
				sum+=add; 
				add++; 
			}
			else 
				add=1; 
		} 
		printf("%d\n", sum);
	}
}
