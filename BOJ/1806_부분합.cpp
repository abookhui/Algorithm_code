#include<iostream>
#include<vector>
#define Max 100001
using namespace std;

int n, s;
int arr[Max];

void input() {
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void sol() {
    int lo = 0, ro = 0;
    int sum = 0,len=Max;

    while (lo <= ro) {
        if (sum >= s) {
            int val = ro - lo;

            len = min(len, val);
            sum -= arr[lo++];
        }
        else if (ro == n) break;
        else sum += arr[ro++];
    }

    if (len == Max) printf("0\n");
    else cout << len << '\n';
}

void solve() {
    input();
    sol();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
