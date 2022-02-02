
// 마인크래프트 #18111



//
//#include<iostream>
//
//using namespace std;
//
//int arr[502][502];
//int min_t = 1000000000; //10^9
//int max_h = -1;
//
//int main() {
//	
//	int n, m, b;
//
//	cin >> n >> m >> b;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> arr[i][j];
//		}
//	}
//
//	for (int k = 0; k <= 256; k++) {
//		int inven = 0; // 인벤 시간 : 1
//		int del = 0; // 제거 시간 : 2
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				int h = arr[i][j] - k;
//
//				if (h < 0)
//					inven -= h;
//
//				else
//					del += h;
//
//			}
//		}
//		if (del + b >= inven) {
//			int time = 2 * del + inven;
//
//			if (min_t >= time) {
//				min_t = time;
//				max_h = k;
//			}
//		}
//	}
//
//	cout << min_t << " " << max_h;
//}
