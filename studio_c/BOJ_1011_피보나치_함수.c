/*  괄호
	오/왼 괄호의 개수가 같아야하고 왼쪽이 오른쪽보다 먼저 
	나와야 함

	스택을 이용하자
	가장 가까운 거리에 있는 괄호들 끼리 서로 짝이 맞아야함
	( 가 나오면 push )나 나오면 pop 해 검사

	스택은 항상 최근에 삽입한것이 먼저 필요한 경우에 유용함
*/

#include<stdio.h>
#include<string.h>

char stack[50];
int top = 0;

int check_func(char* p);

void push(char p);
char pop();
int empty();

int main() {

	int test; scanf("%d", &test);

	char p[50];
	for (int i = 0; i < test; i++) {
		scanf("%s", p);

		if (check_func(p)) {
			printf("Y\n");
		}
		else {
			printf("N\n");
		}
	 }
	
}

int check_func(char* p) {
	int result = 1;
	int len = strlen(p);

	for (int i = 0; i < len; i++) {
		
		if (p[i] == '(') {
			push(p[i]);
		}
		else {
			if (empty()) {
				result = 0;
				break;
			}
			else {
				pop();
			}
		}
	}
	if (!empty()) {
		result = 0;
	}
	while (!empty()) {
		pop();
	}
	return result;
}

void push(char p) {
	stack[top++] = p;
}
char pop() {
	return stack[--top];
}
int empty() {
	top = 0;
	return top;
}