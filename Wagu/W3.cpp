#include <iostream>
#include <vector>

using namespace std;
int n, m, q;

vector<vector<int>> moveStructures(vector<vector<int>>& grid) {
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                if (grid[i + 1][j] == 0) {
                    grid[i][j] = 0;
                    grid[i + 1][j] = 1;
                }
            }
        }
    }

    return grid;
}
vector<vector<int>> rotateClockwise(const vector<vector<int>>& grid) {
    vector<vector<int>> rotated(m, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rotated[j][n - 1 - i] = grid[i][j];
        }
    }

    return rotated;
}
vector<vector<int>> rotateCounterclockwise(const vector<vector<int>>& grid) {
    vector<vector<int>> rotated(m, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rotated[m - 1 - j][i] = grid[i][j];
        }
    }

    return rotated;
}
int main() {
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << "q 입력: ";
    cin>> q;
    vector<vector<int>> rotated;
    if(q==1) rotated = rotateClockwise(grid);
    else if(q==-1) rotated = rotateCounterclockwise(grid);


    vector<vector<int>> result = moveStructures(rotated);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

}