#include<iostream>
using namespace std;
#define inf 1000000

int w[5][5] = {
    {0,7,4,6,1},
    {inf,0,inf,inf,inf},
    {inf,2,0,5,inf},
    {inf,3,inf,0,inf},
    {inf,inf,inf,1,0}
};

int visited[5];

int dist[5], min_node;

int get_small_node(){
    int min = inf;
    int minpos= 0;
    for(int i=0;i<5;i++){
        if(dist[i] < min && !visited[i]) {
            min = dist[i];
            minpos = i;
        }
    }
    return minpos;
}
void dijkstra(int start){
    for(int i=0;i<5;i++){
        dist[i] = w[start][i];
    }
    visited[start] = 1;
    for(int i = 0;i<5-1;i++){
        min_node = get_small_node();
        visited[min_node] = 1;
        for(int j=0;j<5;j++){
            if(!visited[j]) 
                if(dist[min_node] + w[min_node][j] < dist[j])
                    dist[j] = dist[min_node] + w[min_node][j];
        }

    }
}
int main(){
    dijkstra(0);

    for(int i=0;i<5;i++){
        printf("%d\n",dist[i]);
    }
}