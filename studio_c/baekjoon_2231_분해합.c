#include <stdio.h>

int main() {
    int N, temp, a = 0, M = 0;
    scanf("%d", &N);
    temp = N;

    while (temp > 0) {
        temp /= 10;
        a++;
    }

    temp = N;
    temp = temp - a * 9;
    if (temp < 0) temp = 0;

    int num, sum = 0;
    for (int i = temp; i <= N; i++) {
        num = i;
 
        sum += num;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        if (sum == N) {
            M = i;
            break;
        }
      
    }

    printf("%d\n", M);
}
