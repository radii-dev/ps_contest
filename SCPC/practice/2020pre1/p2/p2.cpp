#include <iostream>
#include <vector>

using namespace std;

int Answer;
int n, k;
int X[3001], Y[3001];
int dp[3001][3001];

void readInput() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) cin >> X[i];
	for (int i = 1; i < n; i++) cin >> Y[i];
}

void solve() {
	readInput();
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			bool isFin = false;

		}
	}
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