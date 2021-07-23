//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int Answer;
//int cnt = 0;
//
//void haveFriend(int idx, vector<int> Di, vector<bool>* Check) {
//	Check->at(idx) = true;
//	if (Di[idx] >= Di.size()) return;
//	if (Check->at(idx) == true) {
//		cnt--;
//		return;
//	}
//	haveFriend(Di[idx], Di, Check);
//}
//
//void solve(vector<int> Di, vector<bool>* Check) {
//	cnt = 0;
//	for (int i = 0; i < Di.size(); i++) {
//		if (Check->at(i) == false) {
//			haveFriend(i, Di, Check);
//			cnt++;
//		}
//	}
//}
//
//int main(int argc, char** argv)
//{
//	int T, test_case;
//	int N;
//	freopen("p1sample_input.txt", "r", stdin);
//
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		Answer = 0;
//		/////////////////////////////////////////////////////////////////////////////////////////////
//		cin >> N;
//		vector<int> Di;
//		vector<bool> CheckList(N);
//		for (int i = 0; i < N; i++) {
//			int tmp;
//			cin >> tmp;
//			Di.push_back(tmp + i);
//		}
//		solve(Di, &CheckList);
//		Answer = cnt;
//		/////////////////////////////////////////////////////////////////////////////////////////////
//
//		 // Print the answer to standard output(screen).
//		cout << "Case #" << test_case + 1 << endl;
//		cout << Answer << endl;
//	}
//
//	return 0;//Your program should return 0 on normal termination.
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int Answer;
//int cnt = 0;
//
//void haveFriend(int idx, vector<int> Di, bool *Check) {
//	Check[idx] = true;
//	if (Di[idx] >= Di.size()) return;
//	if (Check[idx] == true) {
//		cnt--;
//		return;
//	}
//	haveFriend(Di[idx], Di, Check);
//}
//
//void solve(vector<int> Di, bool *Check) {
//	cnt = 0;
//	for (int i = 0; i < Di.size(); i++) {
//		if (Check[i] == false) {
//			haveFriend(i, Di, Check);
//			cnt++;
//		}
//	}
//}
//
//int main(int argc, char** argv)
//{
//	int T, test_case;
//	int N;
//	freopen("p1sample_input.txt", "r", stdin);
//
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		Answer = 0;
//		/////////////////////////////////////////////////////////////////////////////////////////////
//		cin >> N;
//		vector<int> Di;
//		bool CheckList[100000] = { false, };
//		for (int i = 0; i < N; i++) {
//			int tmp;
//			cin >> tmp;
//			Di.push_back(tmp + i);
//		}
//		solve(Di, CheckList);
//		Answer = cnt;
//		/////////////////////////////////////////////////////////////////////////////////////////////
//
//		 // Print the answer to standard output(screen).
//		cout << "Case #" << test_case + 1 << endl;
//		cout << Answer << endl;
//	}
//
//	return 0;//Your program should return 0 on normal termination.
//}

#include <iostream>
#include <vector>

using namespace std;

int Answer;
int cnt = 0;
vector<int> Di;
bool CheckList[1000001];

void haveFriend(int idx) {
	CheckList[idx] = true;
	if (Di[idx] >= Di.size()) return;
	if (CheckList[idx] == true) {
		cnt--;
		return;
	}
	haveFriend(Di[idx]);
}

void solve() {
	cnt = 0;
	for (int i = 0; i < Di.size(); i++) {
		if (CheckList[i] == false) {
			cnt++;
			haveFriend(i);
		}
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	int N;
	freopen("p1sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		Di.clear();
		fill_n(CheckList, sizeof(CheckList), false);
		cin >> N;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			Di.push_back(tmp + i);
		}
		solve();
		Answer = cnt;
		/////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
