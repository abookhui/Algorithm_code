#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

int oz[2]={0,};
int main(){

    char *s=(char*)malloc(sizeof(char)*1000001);
    scanf("%s",s);

    char cmp=s[0];
    oz[cmp-48]++;
    for(int i=1;i<strlen(s);i++){
        if(cmp==s[i]) continue;
        else {
            if(s[i]=='0'){
                cmp='0';
                oz[0]++;
            }
            else if(s[i]=='1'){
                cmp='1';
                oz[1]++;
            }
        }
    }
    cout<<min(oz[0],oz[1])<<'\n';
}