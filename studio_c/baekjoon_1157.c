#include<stdio.h>
#include<string.h>
int main() {
	char p[1000000]; int arr[26] = { 0, }; int len; int max, chk = 0 , result = 0;
	scanf("%s", p); 
	len = strlen(p);
	for (int i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j < len; j++) {
			if (i == p[j]) {
				arr[i - 'a']++;
			}
		}
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		for (int j = 0; j < len; j++) {
			if (i == p[j]) {
				arr[i - 'A']++;
			}
		}
	}
	max = arr[0];
	for (int i = 0; i < 26; i++) {
		if (max < arr[i]) {
			max = arr[i];
			chk = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max == arr[i]) 
			result++; 
	} 
	if (result > 1) 
		printf("?\n");
	else printf("%c", chk + 'A');
	return 0;
}

