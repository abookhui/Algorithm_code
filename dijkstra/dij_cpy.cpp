#include<iostream>
#include<vector>
using namespace std;
#define size 5
#define inf 1000000
bool visit[size] = {0,};
int map[size][size];
int dist[size];

int w[size][size] = {
    {0,7,4,6,1},
    {inf,0,inf,inf,inf},
    {inf,2,0,5,inf},
    {inf,3,inf,0,inf},
    {inf,inf,inf,1,0}
};

int get_small_pos(){
    int min_val = inf;
    int min_pos = 0;
    for(int i=0;i<size;i++){
        if(min_val > dist[i]){
            min_val = dist[i];
            min_pos = i;
        }
    }
    return min_pos;
}
void dijkstra(int start){
    visit[start] = true;
    for(int i=0;i<size;i++){
        dist[i] = w[start][i];
    }

    for(int i=0;i<size-1;i++){
        int idx = get_small_pos();
        visit[idx] = true;
        for(int j=0;j<size;j++){
            if(!visit[j])
                if(dist[idx] + w[idx][j] < dist[j])
                    dist[j] = dist[idx] + w[idx][j];
                
        }
    }
}


int main(){
    dijkstra(0);
   for(int i=0;i<size;i++){
     cout<<dist[i]<<' ';
   }
     
}