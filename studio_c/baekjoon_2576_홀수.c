#include <stdio.h>


int main() {
    int a;
    int n = -1;
    int sum = 0;
    int min = 100;
    for (int i = 0; i < 7; i++) {
        scanf("%d", &a);
        if (a % 2 != 0) {
            n = 0;
            sum += a;
            if (min > a) {
                min = a;
            }
        }
    }
    if (n == -1) {
        printf("%d\n", n);
    }
    else {
        printf("%d\n", sum);
        printf("%d\n", min);
    }
}