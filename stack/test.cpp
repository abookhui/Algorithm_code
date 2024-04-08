#include<iostream>
#include<string.h>
#define max_size 10001
using namespace std;

int stack[max_size];
int cnt=0; // stack size

void push(int x){stack[cnt++] = x;}
void pop(){printf("%d\n",(cnt>0)?stack[--cnt]:-1);}
void size(){printf("%d\n",cnt);}
void empty(){printf("%d\n",(cnt>0)?0:1);}
void top(){printf("%d\n",(cnt>0)?stack[cnt-1]:-1);}

int main(){
    int n;
    cin>>n;

    while(n--){
        string order;
        cin>>order;  // string 은 scanf로 입력 받지 못함 why 공백~~~있음
        if(!order.compare("push")){
            int x;
            scanf("%d",&x);
            push(x);
        }
        else if(!order.compare("pop")) {pop();}
        else if(!order.compare("top")) top();
        else if(!order.compare("size")) size();
        else if(!order.compare("empty")) empty();
    }

}