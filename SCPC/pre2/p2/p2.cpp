#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int R;

void readInput() {
	cin >> R;
}

void solve() {
	int ans = 0;
	readInput();
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

