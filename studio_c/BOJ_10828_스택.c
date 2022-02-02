//  입력한 문자열이 각 명령과 같은지를 strcmp함수로 비교하고 각 명령에 따른 함수를 만들자.

#include<stdio.h>
#include<string.h>

int stack[10001];
int cnt = 0;

void push(int num) {
	stack[cnt] = num;
	cnt++;
}

void pop() {
	if (cnt != 0) {
		cnt--;
		printf("%d\n", stack[cnt]);
		stack[cnt] = 0;

	}
	else {
		printf("%d\n", -1);
	}
}

void size() {
	printf("%d\n", cnt);
}

void empty() {
	if (cnt != 0) {
		printf("%d\n", 0);
	}
	else {
		printf("%d\n", 1);
	}
}
void top() {
	if (cnt != 0) {
		printf("%d\n", stack[cnt - 1]);
	}
	else {
		printf("%d\n", -1);
	}
}

int main() {
	int n; int num;
	char p[6];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", p);

		if (strcmp(p, "push") == 0) {
			scanf("%d", &num);
			push(num);
		}

		else if (strcmp(p, "pop") == 0) {
			pop();
		}

		else if (strcmp(p, "size") == 0) {
			size();
		}

		else if (strcmp(p, "empty") == 0) {
			empty();
		}

		else if (strcmp(p, "top") == 0) {
			top();
		}
	}
}