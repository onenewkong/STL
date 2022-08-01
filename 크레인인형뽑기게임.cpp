#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;

	for (int& i : moves) {
		for (vector<int>& u : board) {
			if (u[i - 1] != 0) {
				if (s.empty() || s.top() != u[i - 1]) {
					s.push(u[i - 1]);
				}
				else {
					s.pop();
					answer += 2;
				}
				u[i - 1] = 0;
				break;
			}
		}
	}

	return answer;