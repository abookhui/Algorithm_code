#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
    
    int t;
    cin>> t;

    while(t--){
        string s;
        cin>> s;
        int chk =0;
        char cmp = s[0];
        for(int i=1;i<s.size();i++){
            if (cmp != s[i]) {
                printf("YES\n");
                chk = 1;
                s[0] = s[i];
                s[i] = cmp;
                break;
            }
        }
        if(chk){
            for(int i=0;i<s.size();i++){
                printf("%c",s[i]);
            }printf("\n");
        } 
        else {
            printf("NO\n");
        }
    }
}