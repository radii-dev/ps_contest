#include <iostream>
#include <vector>

using namespace std;

int Answer;

int solve(int num) {
	if (num % 10 == 9)
		return num / 10 + 1;
	else
		return num / 10;
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		int n;
		cin >> n;

		Answer = solve(n);

		// Print the answer to standard output(screen).
		//cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}