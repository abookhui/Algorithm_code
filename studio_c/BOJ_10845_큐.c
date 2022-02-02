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
		printf("%d\n", stack[0]);
		for (int i = 0; i < cnt; i++) {
			stack[i] = stack[i + 1];
		}
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

void front() {
	if (cnt != 0) {
		printf("%d\n", stack[0]);
	}
	else {
		printf("%d\n", -1);
	}
}

void back() {
	if (cnt != 0) {
		printf("%d\n", stack[cnt - 1]);
	}
	else {
		printf("%d\n", -1);
	}
}
int main() {
	int n; scanf("%d", &n);

	char order[6];

	for (int i = 0; i < n; i++) {
		scanf("%s", order);

		if (strcmp(order, "push") == 0) {
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(order, "pop") == 0) {
			pop();
		}
		else if (strcmp(order, "size") == 0) {
			size();
		}
		else if (strcmp(order, "empty") == 0) {
			empty();
		}
		else if (strcmp(order, "front") == 0) {
			front();
		}
		else if (strcmp(order, "back") == 0) {
			back();
		}
	}

}

