#include<iostream>
#include<stack>
using namespace std;

int priority(char op){
    if(op=='*'||op=='/') return 2;
    else if(op=='+'||op=='-') return 1;
    else if(op=='('||op==')') return 0;
}

int main(){
    string me;
    stack<char> op;
    cin>>me;

    for(int i=0;i<me.size();i++){
        switch(me[i]){
            case '+': case '-': case '*': case '/':
                while(!op.empty() && priority(op.top()) >= priority(me[i])){
                    printf("%c",op.top());
                    op.pop();
                }op.push(me[i]);
                break;
            case '(' :
                op.push(me[i]);
                break;
            case ')': 
                while(1){
                    if(op.top()=='(') {
                        op.pop(); 
                        break;
                    }
                    printf("%c",op.top());
                    op.pop();
                }
                break;
            default :
                printf("%c",me[i]);
                break;
            
        }
    }
    while(!op.empty()){
        printf("%c",op.top());
        op.pop();
    }
}