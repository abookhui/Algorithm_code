//#include<stdio.h>
//void func(int n, int f);
//int sum1, sum2, sum = 0;
//void func2(int arr[2]) {
//	for (int k = 1; k >= 0; k--) {
//		printf("%d", arr[k]);
//	}
//}
//void func3(int arr[2], int sum) {
//
//	for (int k = 0; k < 2; k++) {
//		arr[k] = sum % 10;
//		sum /= 10;
//	}
//	for (int k = 1; k >= 0; k--) {
//		printf("%d", arr[k]);
//	}
//}
//int main(void) {		
//	int n, f; 
//	scanf("%d", &n); scanf("%d", &f);
//	func(n, f);
//
//}
//void func(int n, int f) {
//	int i, j; int num1, num2; int arr1[2], arr2[2];
//	if (n % f == 0) {
//		printf("00");
//	}
//	else {
//		for (i = 1;; i++) {
//			n -= i;
//			if (n % f == 0) {
//				sum1 = n;
//				break;
//			}
//		}
//		for (j = 1;; j++) {
//			n += j;
//			if (n % f == 0) {
//				sum2 = n;
//				break;
//			}
//		}
//		num1 = sum1 % 100; num2 = sum2 % 100;
//		if (num1 > num2) {
//			func3(arr2, sum2);
//		}
//		else if (num1 < num2) {
//			func3(arr1, sum1);
//		}
//		else {
//			for (int k = 0; k < 2; k++) {
//				arr1[k] = sum1 % 10;
//				sum1 /= 10;
//				arr2[k] = sum2 % 10;
//				sum2 /= 10;	
//			}
//			if (arr1[0] > arr2[0])
//				func2(arr2);					
//			else 
//				func2(arr1);	
//		}
//	}
//}
//
#include<stdio.h>
int main() {
    int n, f, temp, i;

    scanf("%d %d", &n, &f);

    n = (n / 100) * 100;

    for (i = 0; i < 100; i++) {
        temp = n;
        if ((temp += i) % f == 0)
            break;
    }

    if (i < 10)
        printf("0");

    printf("%d", i);
}


	
