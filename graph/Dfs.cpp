#include<stdio.h>
#include<iostream>  
#include<vector>
using namespace std;
#define num 8
vector<int> arr[num];
int c[num];
int visited[num]={0,};

void dfs(int node){
    if(visited[node]) return;
    visited[node] = 1;
    printf("%d ",node);

    for(int i=0;i<arr[node].size();i++){
        int n = arr[node][i];
        dfs(n);
    }
}

int main(){
    arr[1].push_back(2);
    arr[2].push_back(1);

    arr[1].push_back(3);
    arr[3].push_back(1);

    arr[2].push_back(3);
    arr[3].push_back(2);

    arr[2].push_back(4);
    arr[4].push_back(2);

    arr[5].push_back(2);
    arr[2].push_back(5);

    arr[3].push_back(6);
    arr[6].push_back(3);

    arr[3].push_back(7);
    arr[7].push_back(3);

    arr[4].push_back(5);
    arr[5].push_back(4);

    arr[6].push_back(7);
    arr[7].push_back(6);

    dfs(1);
}

/*
1. 최상단 노드를 확인
2. 최상단 노드에게 방문하지 않은 인접 노드가 있으면 그 노드를 스택에 넣고 방문처리를 한다.
방문하지 않은 인접노드가 없으면 스택에서 뺀다.
*/