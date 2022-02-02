#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector <pair<string, string> > arr;

int sol(int lo, int ro, string a) {

    int mid = (lo + ro) / 2;

    if (arr[mid].first == a) {
        return mid;
    }

    return arr[mid].first > a ? sol(lo, mid, a) : sol(mid + 1, ro, a);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    string address, pass;
    for (int i = 0; i < n; i++) {
        cin >> address >> pass;
        arr.push_back({ address,pass });
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; i++) {
        cin >> address;
        int idx = sol(0, n - 1, address);
        cout << arr[idx].second << '\n';
    }
}