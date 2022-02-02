#include<iostream>
#include<cmath>

using namespace std;

int n,r,c;
int ans;
void z(int b, int a, int size){

	if(a==c && b==r){
		cout<<ans<<"\n";		
		return;
	}

	if(r < (b + size) && b <= r && c < (a + size) && a<=c){
		z(b,a,size/2); // 1사
		z(b,a+size/2,size/2); // 2사
		z(b+size/2,a,size/2);  //3사
		z(b+size/2,a+size/2,size/2);  //4사
	}
	else {
		ans+=size*size;
	}

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>r>>c;
	z(0,0,pow(2,n)); 

}