#include<stdio.h>
#include<string.h>

char stack[50];
int cnt = 0;

void push(char c) {
	stack[cnt] = c;
	cnt++;
}

void pop() {
	cnt--;
}

int empty() {
	if (cnt != 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int check(char* str);

int main() {
	int test;
	scanf("%d", &test);

	char p[50];

	for (int i = 0; i < test; i++) {
		scanf("%s", p);

		if (check(p) == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

	}
}

int check(char* str) {
	int len = strlen(str);
	int result = 1;

	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			push(str[i]);
		}
		else {
			if (empty() == 1) {
				result = 0;
				break;
			}
			else {
				pop();
			}
		}
	}
	if (empty() == 0) {
		result = 0;
	}
	while (empty() == 0) {
		pop();
	}
	return result;
}
