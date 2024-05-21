#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        vector<int> dp(m + 1);
        for (int i = 0; i < m; ++i) {
            dp[i + 1] = max(dp[i], (b[i] == '1') * (i + 1));
        }

        int answer = 0;
        for (int i = 0, ones = 0; i < n; ++i) {
            if (a[i] == '1') {
                ++ones;
            }
            if (i < m) {
                answer = max(answer, ones + dp[m - 1 - i]);
            }
        }

       // cout << answer << '\n';
        printf("- %d\n", answer);
    }

    return 0;
}
