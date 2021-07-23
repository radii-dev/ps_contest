#include <iostream>
#include <vector>

using namespace std;

int n, t;

void guessFixedA(vector<char> *binA, vector<char> binB) {
	for (int i = t + 1; i <= n; i++) {
		if (binB[i - 1] == '0') binA->at(i - t - 1) = '0';
	}
	for (int i = 1; i <= n - t; i++) {		
		if (binB[i - 1] == '0') binA->at(i + t - 1) = '0';
	}
}

void solve(vector<char> *binA, vector<char> binB) {
	guessFixedA(binA, binB);
	for (int i = 0; i < n; i++) {
		if (binB[i] == '1') {
			if (i + t >= n) {
				if (binA->at(i - t) == 'a') binA->at(i - t) = '1';
			}
			else if (i - t < 0) {
				if (binA->at(i + t) == 'a') binA->at(i + t) = '1';
			}
			else if (binA->at(i + t) != '1' && binA->at(i - t) != '1') {
				if (binA->at(i + t) == 'a') binA->at(i + t) = '1';
				else if (binA->at(i - t) == 'a') binA->at(i - t) = '1';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (binA->at(i) == 'a') binA->at(i) = '0';
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	vector<char> binB;
	freopen("p2sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> n >> t;
		vector<char> binA(n, 'a');
		binB.clear();
		for (int i = 0; i < n; i++) {
			char tmp;
			cin >> tmp;
			binB.push_back(tmp);
		}
		solve(&binA, binB);

		/////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		for (int i = 0; i < n; i++) cout << binA[i];
		cout << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
