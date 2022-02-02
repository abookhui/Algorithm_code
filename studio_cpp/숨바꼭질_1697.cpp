/*
	# 1697 숨바꼭질
	1. 위치가 x 일 때 x-1 or x+1 : 시간 +1;
	2. 위치가 x 일 때 2 * x : 시간 +1

*/
//
//
//
//#include<iostream>
//
//using namespace std;
//
//int n, m;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> m;
//
//	int cnt = 0;
//	while (1) {
//		if (n == m) {
//			cout << cnt;
//			break;
//		}
//
//		else if (n > m) {
//			n--;
//			cnt++;
//		}
//		else {  // n=10 
//			int cmp = abs((n - 1) * 2 - m);  // 18 - 17 =1
//			int cmp1 = abs(2 * n - m);  // 20-17 = 3
//			int cmp2 = abs((n + 1) - m); // 11-17 = 6
//
//			if (cmp < cmp1 && cmp < cmp2) { 
//				cnt += 2;
//				n--;
//				n *= 2;
//			}
//
//			else if (cmp1 >= cmp2) {  // 3>=6
//				n++;
//				cnt++;
//			}
//			else if (cmp1 < cmp2) {  // 6<=3
//				n *= 2;
//				cnt++;
//			}
//		}		
//	}
//}

#include<iostream>
#include<utility>
#include<queue>

using namespace std;

int n, m; int ans;
queue<pair<int, int>>q;
bool visited[100001];

bool chk(int num) {
	if (num < 0 || num>100000 || visited[num]) {
		return false;
	}
	return true;
}

void bfs(int num) {
	while (!q.empty()) {

		int	d = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (d == m) {
			ans = cnt;
			break;
		}

		if (chk(d - 1)) {
			visited[d - 1] = true;
			q.push({ d - 1,cnt + 1 });
		}

		if (chk(d + 1)) {
			visited[d + 1] = true;
			q.push({ d + 1,cnt + 1 });
		}
		if (chk(2 * d)) {
			visited[2 * d] = true;
			q.push({ 2 * d,cnt + 1 });
		}
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	q.push({ n,0 });

	visited[n] = true;
	bfs(n);

	cout << ans;

}