#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int R;

void readInput() {
	cin >> R;
}

//void solve() {
//	int ans = 0;
//	int xy = 0;
//	readInput();
//	int pr = int (pow(R, 2));
//	for (int i = 1; i < R; i++) {
//		int pi = int (pow(i, 2));
//		for (int j = i + 1; j < R; j++) {
//			int pj = int (pow(j, 2));
//			if (pi + pj < pr) ans++;
//			else break;
//		}
//		if (2 * pi < pr) xy++;
//	}
//	ans = ans * 2 + xy;
//	ans = ans * 4 + ((R - 1) * 4 + 1);
//	cout << ans;
//}

//void solve() {
//	int alpha = 0;
//	int ans = 0;
//	readInput();
//	int pr = int(pow(R, 2));
//	for (int i = 1; i < R; i++) {
//		int pi = int(pow(i, 2));
//		for (int j = R - i; j > i; j--) {
//			int cnt = 1;
//			while (pi + int(pow(j + cnt, 2)) < pr) {
//				alpha++;
//				cnt++;
//			}
//		}
//	}
//	ans = int(pow(R + 1, 2)) + pr - 4 + 4 * alpha;
//	cout << ans;
//}

void solve() {
	int alpha = 0;
	int ans = 0;
	readInput();
	int pr = int(pow(R, 2));
	int x = 1; int y = R - 1;
	while (y > 0) {
		x++;
		if (pow(x, 2) + pow(y, 2) < pr) {
			alpha++;
		}
		else {
			y--;
			x = R - y;
		}
	}
	ans = int(pow(R + 1, 2)) + pr - 4 + 4 * alpha;
	cout << ans;
}

//void solve() {
//	int alpha = 0;
//	int ans = 0;
//	readInput();
//	int pr = int(pow(R, 2));
//	int x = R; int y = R; int xy = 0;
//	while (y > 0 && y >= x) {
//		if (x >= 0 && int(pow(x, 2)) + int(pow(y, 2)) >= pr) {
//			if (x == y) xy++;
//			else alpha++;
//			x--;
//		}
//		else {
//			y--;
//			x = y;
//		}
//	}
//	ans = int(pow((2 * R + 1), 2)) - (alpha - 1) * 8 - 4 - 4 * xy;
//	cout << ans;
//}


int main(int argc, char** argv)
{
	int T, test_case;
	freopen("p1sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cout << "Case #" << test_case + 1 << endl;
		solve();  cout << endl;
	}

	return 0;
}

