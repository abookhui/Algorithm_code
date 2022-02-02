#include<iostream>
using namespace std;

typedef struct{
    int hour;
    int minute;
    int sec;
}tlrks;

tlrks t[2];

int time_difference(){
    int val=(t[1].hour-t[0].hour)*3600+(t[1].minute-t[0].minute)*60+(t[1].sec-t[0].sec);

    return val;
}
int main(){
    tlrks ans; //시간
    scanf("%d:%d:%d",&t[0].hour,&t[0].minute,&t[0].sec);
    scanf("%d:%d:%d",&t[1].hour,&t[1].minute,&t[1].sec);

    int v=time_difference();

    ans.hour=v/3600;
    v%=3600;
    ans.minute=v/60;
    v%=60;
    ans.sec=v;

    printf("%02d:%02d:%02d\n",ans.hour,ans.minute,ans.sec);

    return 0;
}
