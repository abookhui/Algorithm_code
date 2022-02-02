#include <iostream>

using namespace std;

int n, m;
int arr[9] = { 0, };
bool visited[9] = { false, };

void func(int x, int y) {

    if (y == m) {

        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        return;
    }

    for (int i = x; i <= n; i++) {

        if (!visited[i]) {
            visited[i] = true;
            arr[y] = i;

            func(i + 1, y + 1);
            visited[i] = false;
        }
    }
}

int main() {

    cin >> n >> m;
    func(1, 0);

}