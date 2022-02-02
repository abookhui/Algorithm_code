/*	구조체로 푼다. 정렬해서 맨 앞 뒤 name 출력.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[15];
	int day;
	int mon;
	int year;
}age;


int compare(const void* a, const void* b);

int main() {

	int test; scanf("%d", &test);

	age p[100];

	for (int i = 0; i < test; i++) {
		scanf("%s %d %d %d", p[i].name, &p[i].day, &p[i].mon, &p[i].year);
	}

	qsort(p, test, sizeof(age), compare);

	printf("%s\n%s\n",p[test - 1].name, p[0].name);
}

int compare(const void* a, const void* b) {

	age* A = (age*)a;
	age* B = (age*)b;

	if (A->year > B->year) {
		return 1;
	}
	else if (A->year == B->year) {
		if (A->mon > B->mon) {
			return 1;
		}
		else if (A->mon == B->mon) {
			if (A->day > B->day) {
				return 1;
			}
			return -1;
		}
		return -1;
	}
	return -1;
}