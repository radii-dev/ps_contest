#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
int n, k;
int X[3001], Y[3001];
int psX[3001], psY[3001];		//prefix sum of X and Y
int dp[3001][3001];

void readInput() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) cin >> X[i];
	for (int i = 1; i < n; i++) cin >> Y[i];
}

void solve() {
	readInput();
	for (int i = 1; i < n; i++) psX[i] = psX[i - 1] + X[i];
	for (int i = 1; i < n; i++) psY[i] = psY[i - 1] + Y[i];

	int ans1 = 0; int ans2 = 0;
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			bool isFin = false;
			if (i > 0) {
				int ptnextX = lower_bound(psX, psX + i + 1, psX[i] - k) - psX;
				int caseX = i - ptnextX;
				int sumX = 0;
				for (int l = 1; l <= caseX; l++) sumX += dp[i - l][j];
				if (sumX < caseX) isFin = true;
			}
			if (j > 0) {
				int ptnextY = lower_bound(psY, psY + j + 1, psY[j] - k) - psY;
				int caseY = j - ptnextY;
				int sumY = 0;
				for (int l = 1; l <= caseY; l++) sumY += dp[i][j - l];
				if (sumY < caseY) isFin = true;
			}
			if (isFin) dp[i][j] = 1;
			else dp[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j]) ans1++;
			else ans2++;
		}
	}
	cout << ans1 << " " << ans2;
}

int main(int argc, char** argv)
{
	int T, test_case;
	freopen("p2sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cout << "Case #" << test_case + 1 << endl;
		solve();  cout << endl;
	}

	return 0;
}