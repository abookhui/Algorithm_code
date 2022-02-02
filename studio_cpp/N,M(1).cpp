#include <iostream>

using namespace std;

int N, M;

bool visited[8] = { false, };
int check[8];

void solve(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << check[i] << ' ';
        cout << '\n';

        return;
    }

    for (int i = 0; i < N; i++)
    {
        // 가지치기

        if (!visited[i])
        {
            visited[i] = true;
            check[cnt] = i + 1;

            solve(cnt + 1);

            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;

    solve(0);

    return 0;
}
