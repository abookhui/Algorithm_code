#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

//int arr[4] = { 1,2,3,4 };
int A[13];
vector<int> arr;
int com[13];
vector<vector<int>>vec;
int N,R;

void input(){
    cin>>N>>R;

    for(int i=0;i<N;i++){
        arr.push_back(i);
    }
}


void combination(int N, int R, int q)
{   
    
	if (R == 0)
	{   
        vector<int>v;
		for (int i = q-1; i >= 0; i--)
		{

            v.push_back(A[i]);
            
		}
		//printf("\n");
        vec.push_back(v);
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<' ';
        // }cout<<'\n';
	}
	else if (N < R)
	{
		return;
	}
	else
	{
		A[R - 1] = arr[N - 1];
		combination(N - 1, R - 1, q);
		combination(N - 1, R, q);
	}


}

int main(void)
{
    input();
	combination(N, R, R);

    for(int i=0;i<vec.size();i++){
        for(int j=0;j<R;j++){
            cout<<vec[i][j]<<' ';
        }cout<<'\n';
    }
	return 0;
}