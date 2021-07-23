#include <iostream>
#include <vector>
#include <string>

using namespace std;
string s, t;
int idx = 0;

bool isPossible() {
	
}

bool solve() {
	if (s.length() < t.length()) return false;
	else {

	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	string tmp;

	cin >> T;
	getline(cin, tmp, '\n');
	for (test_case = 0; test_case < T; test_case++)
	{
		bool Answer;
		s.clear();
		t.clear();
		getline(cin, s, '\n');
		getline(cin, t, '\n');

		Answer = solve();

		cout << "Case #" << test_case + 1 << endl;
		if (Answer) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}

	return 0;
}