#include <stdio.h>

int func(int a, int b) {
    if (b == 0)
        return a;

    return func(b, a % b);
}

int main() {
    int n;
    int x, y;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", x * y / func(x, y));
    }
}