#include<iostream>
#include<cmath>
#define S 200001

using namespace std;

string binary="1001"; // 0 1 2
string num;
string ans;
int n;
long long input_arr[S];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n;

	long long max_val=0;
	for(int i=0;i<n;i++){
		cin>>input_arr[i];
		if(max_val<input_arr[i]){
			max_val=input_arr[i];
		}
	}

	int idx = 0;
	while (max_val) {
		max_val /= 2;
		idx++;
	}

	for(int i=3;i<=idx;i++){
		num=binary;
		for(int j=0;j<pow(2,i);j++){
			if(num[j]=='1'){
				num[j]='0';
			}
			else if(num[j]=='0'){
			num[j]='1';
			}
		}
		binary+=num;		
	}

	for(int i=0;i<n;i++){
		ans[i]=binary[input_arr[i]-1];
	}
	cout<<ans<<'\n';
}