#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

int n, m;
int arr[8];
bool visit[8];
vector<int>v;

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
}

void sol(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        } cout << "\n";

        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (visit[i]) continue;

        visit[i] = true;
        arr[idx] = v[i];
        sol(idx + 1);

        visit[i] = false;
    }
}

void solve() {
    input();
    sol(0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}