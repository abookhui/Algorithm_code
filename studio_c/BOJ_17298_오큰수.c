#include <stdio.h>
#define max 1000000

int num[max];
int ans[max];
int main()
{
    int n;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    ans[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; i + j < n; j++)
        {
            if (num[i] < num[i + j])
            {
                ans[i] = num[i + j];
                break;
            }
            if (num[i] >= num[i + j] && ans[i + j] == -1)
            {
                ans[i] = -1;
                break;
            }
            if (num[i] >= num[i + j] && num[i] < ans[i + j])
            {
                ans[i] = ans[i + j];
                break;
            }
        }
    }


    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
}




#include<stdio.h>
#include<string.h>
#define max 1000000

int stack[max];
int top = -1;

int arr[max];
int ans[max];

void push(int num) {
    top++;
    stack[top] = num;
}

int pop() {

    return top == -1 ? -1 : stack[top--];
}

int size() {
    return top + 1;
}
int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {   // 수열 입력;
        scanf("%d", &arr[i]);
    }

    memset(ans, -1, sizeof(int) * n);  // ans 모두 -1로 초기화

    for (int i = n - 1; i >= 0; i--) {

        while (size() > 0) {    // top 이 -1 아니면

            int result = pop();

            if (arr[i] < result) {

                push(result);
                ans[i] = result;
                break;
            }
        }
        push(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

}