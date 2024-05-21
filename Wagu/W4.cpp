#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long k;
    cin >> k;

    int n;
    cin >> n;

    vector<int> digits(n);
    for (int i = 0; i < n; ++i) {
        cin >> digits[i];
    }

    // 가장 작은 s를 구함
    sort(digits.begin(), digits.end());
    long long smallest_s = 0;
    for (int i = 0; i < n; ++i) {
        smallest_s = smallest_s * 10 + digits[i];
    }

    // 가장 큰 s를 구함
    reverse(digits.begin(), digits.end());
    long long largest_s = 0;
    for (int i = 0; i < n; ++i) {
        largest_s = largest_s * 10 + digits[i];
    }

    // s는 k로 나눈 나머지가 0이어야 함
    for (long long s = smallest_s; s <= largest_s; s += k) {
        if (s % k == 0) {
            cout << "가장 작은 s: " << smallest_s << endl;
            cout << "가장 큰 s: " << largest_s << endl;
            return 0;
        }
    }

    cout << "해당하는 s가 없습니다." << endl;

    return 0;
}
