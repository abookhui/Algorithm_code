#include<stdio.h>
#include<string.h>

#define size 600000

char left[size];
char right[size];


void reverse(char* s);

int main() {

	scanf("%s", right);

	int test;
	scanf("%d", &test);

	int len_r = strlen(right) - 1;
	int len_l = -1;


	char command;

	while (test-- > 0) {
		scanf(" %c", &command);

		if (command == 'L') {
			if (len_r >= 0) {
				len_l++;
				left[len_l] = right[len_r];
				right[len_r] = '\0';
				len_r--;
			}
		}
		else if (command == 'D') {
			if (len_l >= 0) {
				len_r++;
				right[len_r] = left[len_l];
				left[len_l] = '\0';
				len_l--;
			}
		}
		else if (command == 'B') {
			if (len_r >= 0) {
				right[len_r] = '\0';
				len_r--;
			}
		}
		else if (command == 'P') {
			char x;
			scanf("  %c", &x);
			len_r++;
			right[len_r] = x;
		}
	}

	reverse(left);

	strcat(right, left);

	printf("%s\n", right);
}
void reverse(char* s) {   //left 문자열 뒤집기 함수
	int len = strlen(s);
	char temp;

	for (int i = 0; i < len / 2; i++) {
		temp = s[i];
		s[i] = s[(len - 1) - i];
		s[(len - 1) - i] = temp;
	}
}