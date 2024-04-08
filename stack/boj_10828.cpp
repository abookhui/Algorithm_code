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
        char order[6];
        scanf("%s",&order);
        if(!strcmp(order,"push")){
            int x;
            scanf("%d",&x);
            push(x);
        }
        else if(!strcmp(order,"pop")) {pop();}
        else if(!strcmp(order,"top")) top();
        else if(!strcmp(order,"size")) size();
        else if(!strcmp(order,"empty")) empty();
    }

}