#include <stdio.h>
#include <string.h>

int n;
int arr[100][100] = { 0, };
int visit[100][100] = { 0, };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


int dfs(int color, int x, int y) {
    visit[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
            if (arr[nx][ny] == color && visit[nx][ny] == 0) {
                dfs(color, nx, ny);
            }
        }
    }
    return 0;
}

// red green Àü¿ë
int RG(int x, int y) {
    visit[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
            if ((arr[nx][ny] == 1 || arr[nx][ny] == 2) && !visit[nx][ny]) {
                RG(nx, ny);
            }
        }
    }
    return 0;
}


int main() {
    scanf("%d", &n);

    char str[101];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        for (int j = 0; j < n; j++) {
            if (str[j] == 'R') arr[i][j] = 1;
            else if (str[j] == 'G') arr[i][j] = 2;
            else arr[i][j] = 3;
        }
    }

    int red = 0, green = 0, blue = 0, red_green = 0;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1 && !visit[i][j]) {
                dfs(1, i, j);
                red++;
            }
            if (arr[i][j] == 2 && !visit[i][j]) {
                dfs(2, i, j);
                green++;
            }
            if (arr[i][j] == 3 && !visit[i][j]) {
                dfs(3, i, j);
                blue++;
            }
        }
    }
    
    memset(visit, 0, sizeof(visit));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if ((arr[i][j] == 1 || arr[i][j] == 2) && !visit[i][j]) {
                RG(i, j);
                red_green++;
            }
        }
    }

    int ans1 = red + green + blue;
    int ans2 = red_green + blue;
    printf("%d %d\n", ans1, ans2);
}
