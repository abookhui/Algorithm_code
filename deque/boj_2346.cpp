#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    deque<pair<int,int>> d;// num idx
    for(int i=1;i<=n;i++){
        cin>>x;
        d.push_back({x,i});
    }

    while(!d.empty()){
        int next = d.front().first;
        printf("%d ",d.front().second);
        d.pop_front();
        // 덱의 front에 있는 num을 꺼내주고 그 idx는 출력해 준다.

        if(next > 0){ // 양수 -> 왼쪽에서 오른쪽으로
            next--; 
            while(next!=0){
                d.push_back(d.front());
                d.pop_front();
                next--;
            }

        }
        else { // 음수 -> 오른쪽에서 왼쪽으로
            while(next!=0){
                d.push_front(d.back());
                d.pop_back();
                next++;
            }
        }

    }

}