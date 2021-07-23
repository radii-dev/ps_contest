#include <iostream>
#include <vector>

using namespace std;

bool detWinner(int shoot_num, int a, int b) {
	if (a > b) {
		if (a > (b + (9 - shoot_num) / 2))
			return true;
	}
	else if (a < b) {
		if ((a + (9 - shoot_num) / 2 + 1) < b)
			return true;
	}
	return false;
}

int solve(char* s) {
	int score_a = 0;
	int score_b = 0;
	int count_a = 0;
	int count_b = 0;
	char a_s[10];
	char b_s[10];
	for (int i = 0; i < 10; i++) {
		if (s[i] == '?') {
			if (i % 2) {
				a_s[i] = '1';
				b_s[i] = '0';
			}
			else {
				a_s[i] = '0';
				b_s[i] = '1';
			}
		}
		else {
			a_s[i] = s[i];
			b_s[i] = s[i];
		}
	}

	for (int i = 0; i < 10; i++) {
		if (a_s[i] == '1') {
			if (i % 2) score_a++;
			else score_b++;
		}
		count_a = i;
		if (detWinner(i, score_a, score_b)) 
			break;
	}

	score_a = 0;
	score_b = 0;
	for (int i = 0; i < 10; i++) {
		count_b = i;
		if (b_s[i] == '1') {
			if (i % 2) score_a++;
			else score_b++;
		}
		count_b = i;
		if (detWinner(i, score_a, score_b)) 
			break;
	}

	return (count_a < count_b) ? count_a+1 : count_b+1;
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer;
		char s[10];

		for (int i = 0; i < 10; i++) {
			cin >> s[i];
		}

		Answer = solve(s);

		// Print the answer to standard output(screen).
		//cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}