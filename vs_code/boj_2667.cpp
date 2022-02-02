#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int map[26][26];
bool chk[26][26];
vector<int> v;
int n;
int cnt = 0;

//int d[4][2] = { {-1,0}, {0,1},{1,0},{0,-1} }; 
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool is_True(int a, int b){
    if (a >= 0 && b >= 0 && a <= n && b <= n){
        return true;
    }
    return false;
}
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

        if(is_True(nx,ny)){
		    if (chk[nx][ny] == false && map[nx][ny] == 1) {
			    chk[nx][ny] = true;
			    cnt++;				
              dfs(nx, ny);
		    }
        }
	}
}

int main() {
   
	cin>>n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]); 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j] == false && map[i][j] == 1) {
				chk[i][j] = true;
				cnt++;
				dfs(i, j);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(v.begin(), v.end());

    cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}