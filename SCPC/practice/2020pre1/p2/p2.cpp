#include <iostream>
#include <vector>

using namespace std;

int Answer;
int n, k;
int AwinCase, BwinCase;

char checkWhoWin(char turn, vector<int> leftX, vector<int> leftY) {
	int sumx, sumy;
	for (int i = 0; i < leftX.size(); i++) {
		sumx += leftX.at(i);
	}
	for (int i = 0; i < leftY.size(); i++) {
		sumy += leftY.at(i);
	}
	if (sumx)

}

void simul() {

}

int solve() {

}

int main(int argc, char** argv)
{
	int T, test_case;
	freopen("p2sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		vector<int> X_card;
		vector<int> Y_card;
		cin >> n >> k;
		for (int i = 0; i <= n; i++) {
			int tmp;
			cin >> tmp;
			X_card.push_back(tmp);
		}
		for (int i = 0; i <= n; i++) {
			int tmp;
			cin >> tmp;
			Y_card.push_back(tmp);
		}
		Answer = solve();


		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}