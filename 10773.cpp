#include <iostream>
#include <stack>
using namespace std;

void main() {
	int K;
	int a;
	int sum = 0;

	stack<int> v;

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> a;
		if (a == 0) {
			if (!v.empty()) {
				v.pop();
			}
			else {
				continue;
			}
		}
		else {
			v.push(a);
		}
	}

	while (!v.empty()) {
		sum += v.top();
		v.pop();
	}
}