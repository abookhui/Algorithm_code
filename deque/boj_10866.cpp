#include<iostream>
#include<deque>
using namespace std;


int main(){
    int n;
    cin>>n;
    deque<int> dq;

    while(n--){
        string order;
        cin>>order;

        if(!order.compare("push_front")){
            int x;
            cin>>x;
            dq.push_front(x);
        }
        else if(!order.compare("push_back")){
            int x;
            cin>>x;
            dq.push_back(x);
        }
        else if(!order.compare("pop_front")){
            if(!dq.empty()) {printf("%d\n",dq.front());dq.pop_front();}
            else printf("-1\n");
        }
        else if(!order.compare("pop_back")){
            if(!dq.empty()) {printf("%d\n",dq.back());dq.pop_back();}
            else printf("-1\n");
        }
        else if(!order.compare("size")) printf("%d\n",dq.size());
        else if(!order.compare("empty")) printf("%d\n",dq.empty()?1:0);
        else if(!order.compare("front")) printf("%d\n",dq.empty()?-1:dq.front());
        else if(!order.compare("back")) printf("%d\n",dq.empty()?-1:dq.back());
    }
}