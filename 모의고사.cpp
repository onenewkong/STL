#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer1 = { 1, 2, 3, 4, 5 };
vector<int> answer2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> answer3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

int check(vector<int> answers, vector<int> compare) {
	int count = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == compare[i % compare.size()]) {          
			count++;
		}
	}
	return count;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> v;

	v.push_back(check(answers, answer1));
	v.push_back(check(answers, answer2));
	v.push_back(check(answers, answer3));

	int max = *max_element(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (max == v[i]) {
			answer.push_back(i + 1);
		}
	}

	return answer;
}
