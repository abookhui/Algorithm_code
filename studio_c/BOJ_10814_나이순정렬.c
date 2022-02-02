#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[101];
}age_name;

int cmp_num(void* a, void* b);

int main(void)
{
    int n;

    scanf("%d", &n);

    age_name* arr = (age_name*)malloc(n * sizeof(age_name));

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &arr[i].age, arr[i].name);
    }

    qsort(arr, n, sizeof(age_name), cmp_num);

    for (int i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].age, arr[i].name);
    }

    free(arr);
}
int cmp_num(void* a, void* b)
{
    age_name* m1 = (age_name*)a;
    age_name* m2 = (age_name*)b;
    return (*m1).age - (*m2).age;
}