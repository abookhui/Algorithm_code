// #include<stdio.h>

// typedef struct {
//     float x;
//     float y;
// }vector;

// vector get_vector_sum(vector a, vector b){
//     vector ans;
//     ans.x=a.x+b.x;
//     ans.y=a.y+b.y;
//     return ans;
// }

// int main(){
//     vector a ={2.0,3.0};
//     vector b= {4.0, 5.0};

//     vector sum=get_vector_sum(a,b);

//     printf("%f %f\n",sum.x,sum.y);
// }

#include<stdio.h>

typedef struct {
    float x;
    float y;
}vector;

vector get_vector_sum(vector *a, vector *b){
    vector ans;
    ans.x=(*a).x+(*b).x;
    ans.y=(*a).y+(*b).y;
    return ans;  
}

int main(){
    vector a ={2.0,3.0};
    vector b= {4.0, 5.0};

    vector sum=get_vector_sum(&a,&b);

    printf("%f %f\n",sum.x,sum.y);
}