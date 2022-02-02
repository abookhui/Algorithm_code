#include<stdio.h>

int gcd(int a, int b);

int main() {

    int test, num; int arr[100]; int j;
    scanf("%d", &test);

    for (int i = 0; i < test; i++) {
        long long int sum = 0;
        scanf("%d", &num);
        for (j = 0; j < num; j++) {
            scanf("%d", &arr[j]);
        }
        for (j = 0; j < num - 1; j++) {
            for (int k = j + 1; k < num; k++) {
                sum += gcd(arr[j], arr[k]);
            }
        }

        printf("%lld\n", sum);
    }
}

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}