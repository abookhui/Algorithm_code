#include<iostream>
#include<stack>
using namespace std;

bool chk(char c){
    if('A'<=c && c<='Z') return 1;
    else return 0;
}

int main(){
    int n;
    string s;
    stack<double> num; // 피연산자 스택에 넣음
    double alph[26];
    scanf("%d",&n);
    cin>>s;

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        alph[i] = (double)x;
    }

    for(int i=0;i<s.size();i++){
        if(chk(s[i])){  // 피연산자면 스택에 넣어줌
            int idx = s[i] - 'A';
            //printf("---s[%d]: %c  idx: %d alph[%d]: %f--\n",i,s[i],idx,idx,alph[idx]);
            num.push(alph[idx]);
        }
        else{ // 연산자이면 값 계산해서 다시 스택에 넣어줌
            char op = s[i];
            double a = num.top();
            num.pop();
            double b = num.top();
            num.pop();
            //printf("%f %c %f\n",a,s[i],b);
            switch (op){
                case '+': num.push(b+a); break;
                case '-': num.push(b-a); break;
                case '*': num.push(b*a); break;
                case '/': num.push(b/a); break;
            }
        }
    }
    printf("%.2f\n",num.top());
}