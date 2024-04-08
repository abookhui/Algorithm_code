#include<iostream>
#include<queue>
#include<string.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    queue<int> q;
    while(n--){
        char order[6];
        scanf("%s",order);
        if(!strcmp(order,"push")){
            int x;
            scanf("%d",&x);
            q.push(x);
        }
        else if(!strcmp(order,"pop")){
            if(q.empty()) {printf("-1\n");}
            else {printf("%d\n",q.front()); q.pop();}
        }
        else if(!strcmp(order,"size")) printf("%d\n",q.size());
        else if(!strcmp(order,"empty")) printf("%d\n",q.empty()?1:0);
        else if(!strcmp(order,"front")){
            if(q.empty()) {printf("-1\n");}
            else {printf("%d\n",q.front());}
        }
        else if(!strcmp(order,"back")){
            if(q.empty()) {printf("-1\n");}
            else {printf("%d\n",q.back());}
        }
    }
}