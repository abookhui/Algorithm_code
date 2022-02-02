#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int num,t;
int f[43]={1,2};

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    cin>>t;

    for(int i=2;i<43;i++){
        f[i]=f[i-1]+f[i-2];
    }

   	while (t--) {
		int k;
		cin >> num;

		vector<int> ans;
		while (num) {
			for (int i = 0; i < 43; i++) {
				if (f[i] <= num) {
                    t = f[i];
                }
			}
			num -= k;
			ans.push_back(t);
		}
		for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << ' ';
        }
		cout << '\n';
	}
}
