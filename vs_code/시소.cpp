#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, a;
vector<int> v;
int ans;

int f(int a,int b){
	return a>b ? a-b : b-a;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int d = n / 2;


	int ro = v.size() - 1, lo = 0;
	int sum_l = 0, sum_r = 0;


	
	if (n % 4 == 0) { // 4배수
		while (lo < d - 1 && (v.size() - d < ro)) {
			sum_l += v[lo] + v[ro];
			lo++; ro--;
		}
		for (int i = d - 1; i <= v.size() - d; i++) {
			sum_r += v[i];
		}

		ans = sum_r > sum_l ? sum_r - sum_l : sum_l - sum_r;
	}
	
	else if (n == 2) {  //2
		ans=v[1] - v[0];
	}
	
	else if(n%2==0&&(n/2)%2!=0) {  //짝수 and 하나 골라야할때
		int d=(n-2)/4; 
		int r=0,l=0;
		
		for(int i=0;i<d;i++){
			sum_l+=v[i];
		}
		for(int i=v.size();i>=v.size()-d;i--){
			sum_r+=v[i];
		}
		r=sum_r + v[v.size()-d], l = sum_l +v[d];
		
		ans = f(r,sum_l)>f(l,sum_r)?f(l,sum_r):f(r,sum_l);
		
	}
	
	else if(n%2!=0) {//홀수
		int d=n/2;
		
		for(int i=0;i<d;i++){
			sum_l+=v[i];
		}
		for(int i=v.size();i>=v.size()-d;i--){
			sum_r+=v[i];
		}
		
		int r=sum_r + v[d], l = sum_l +v[d];
		
		ans = f(r,sum_l)>f(l,sum_r)?f(l,sum_r):f(r,sum_l);
		
	}
	else { // 더 더하는 
		
	}
	
	printf("%d\n", ans);
}

// #include<iostream>
// #include<algorithm>

// using namespace std;

// int arr[1001];
// int arr_l[1001] = { 0, };
// int arr_r[1001] = { 0, };

// int n;
// int lo = 0, a = 0;
// int ro = 0, b = 0;

// int main(void) {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);

// 	cin >> n;

// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 	}

// 	sort(arr, arr + n, greater<int>());

// 	for (int i = 0; i < n; i++) {
// 		if (a <= b) {
// 			a += arr[i];
// 			arr_l[lo] = arr[i];
// 			lo++;
// 		}
// 		else {
// 			b += arr[i];
// 			arr_r[ro] = arr[i];
// 			ro++;
// 		}
// 	}
// 	int ans = a-b>=0?a-b:b-a;
// 	cout <<ans << '\n';

// }