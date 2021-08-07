#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
string text;
vector<int> pattern[500];

void readInput() {
	cin >> N >> K;
	cin >> text;
	for (int i = 0; i < K; i++) {
		string tmp; int count = 1;
		int alphabet[127] = { 0, };
		cin >> tmp;
		for (string::iterator iter = tmp.begin(); iter != tmp.end(); ++iter) {
			if (alphabet[(int)*iter] == 0) {
				pattern[i].push_back(count);
				alphabet[(int)*iter] = count;
				count++;
			}
			else pattern[i].push_back(alphabet[(int)*iter]);
		}
	}
}

void solve() {
	int ans = 0;
	readInput();
	for (int i = 0; i < K; i++) {
		int k = 0;
		while (k + pattern[i].size() <= text.size()) {
			int count = 1;
			int alphabet[127] = { 0, };
			vector<int> slicetext;
			for (int j = k + 0; j < k + pattern[i].size(); j++) {
				if (alphabet[(int)text[j]] == 0) {
					slicetext.push_back(count);
					alphabet[(int)text[j]] = count;
					count++;
				}
				else slicetext.push_back(alphabet[(int)text[j]]);
			}
			if (slicetext == pattern[i]) ans++;
			k++;
		}
	}
	cout << ans;
}

int main(int argc, char** argv)
{
	int T, test_case;
	freopen("p4sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cout << "Case #" << test_case + 1 << endl;
		solve();  cout << endl;
	}

	return 0;
}

