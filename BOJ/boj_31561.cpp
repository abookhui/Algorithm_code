#include<iostream>
using namespace std;

int main(){
    int m;
    double ans;
    cin>>m;
    if(m<=30){
        ans = (double)m / 2;
        printf("%.1f\n",ans);
    }
    else {
        m -= 30;
        ans = (double)m * (3.0/2.0)+15;
        printf("%.1f\n",ans);
    }
}
    


