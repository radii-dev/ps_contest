#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M, K;

bool findCycleUtil(int vertex, bool* visited, bool* recur, vector <vector <int>>& adj) {
	visited[vertex] = true;
	recur[vertex] = true;

	for (int i = 0; i < adj[vertex].size(); i++) {
		int adjVertex = adj[vertex].at(i);
		if (!visited[adjVertex] && findCycleUtil(adjVertex, visited, recur, adj))
			return true;
		else if (recur[adjVertex])
			return true;
	}

	recur[vertex] = false;
	return false;
}

bool findCycle(vector <vector <int>> &adj) {
	bool visited[500] = { false, };
	bool recur[500] = { false, };
	for (int i = 0; i < N; i++) {
		if (findCycleUtil(i, visited, recur, adj)) return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	int T, test_case;
	freopen("p3sample_input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> N >> M >> K;
		vector<vector<int>> adjList(N);
		vector<char> Answer;
		for (int i = 0; i < M; i++) {
			int tmp[2];
			cin >> tmp[0] >> tmp[1];
			adjList[tmp[0] - 1].push_back(tmp[1] -1);
		}
		for (int i = 0; i < K; i++) {
			int tmp[2];
			cin >> tmp[0] >> tmp[1];
			adjList[tmp[0] - 1].push_back(tmp[1] - 1);
			if (findCycle(adjList)) {
				Answer.push_back('1');
				vector<int>::iterator iter = adjList[tmp[0] - 1].end() - 1;
				adjList[tmp[0] - 1].erase(iter);
				adjList[tmp[1] - 1].push_back(tmp[0] - 1);
			}
			else
				Answer.push_back('0');
		}


		/////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		for (int i = 0; i < Answer.size(); i++) cout << Answer[i];
		cout << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}