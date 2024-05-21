// #include<vector>
// #include<iostream>
// #include<stdio.h>
// #include<stdlib.h>
// using namespace std;

// typedef struct{
//     int x,y;
// }ele;

// int compare(const void *a, const void *b){
//     ele *p1 = (ele *)a;
//     ele *p2 = (ele *)b;
//     if(p1->x==p2->x) return p1->y-p2->y;
//     else return p1->x-p2->x;
// }

// int main(){
//     int n; 
//     cin>>n;
//     vector<ele> v;
//     while(n--){
//         ele a;
//         cin>>a.x>>a.y;
//         v.push_back(a);
//     }
//     qsort(&v[0],v.size(),sizeof(v),compare);

//     for(int i=0;i<n;i++){
//         cout<<v[i].x<<" "<<v[i].y<<"\n";
//     }
// }



#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct element {int x, y;};

int compare(const void* a, const void* b) {
    element p1 = *(element*)a;
    element p2 = *(element*)b;
    return (p1.x == p2.x) ? (p1.y - p2.y) : (p1.x - p2.x);
}
int main() {
    int n;
    vector<element>v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        element a;
        cin >> a.x >> a.y;
        v.push_back(a);
    }
    qsort(&v[0], n, sizeof(element), compare);

    for(element i : v) printf("%d %d\n",i.x,i.y);
}