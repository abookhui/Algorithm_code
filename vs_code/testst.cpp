#include<iostream>
using namespace std;

int main(){
    int n,m,ad;

    scanf("%d + %d = %d",&n,&m,&ad);
    printf("%s\n",((n+m)==ad)?"YES":"NO");

    return 0;
}