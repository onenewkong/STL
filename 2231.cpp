// 분해합

#include <iostream>

using namespace std;

int main() {
	int M;
	int sum;
	int part;

	cin >> M;

	for (int i = 1; i < M; ++i) {
		sum = i;
		part = i;

		while (part) {
			sum += part % 10;
			part /= 10;
		}

		if (M == sum) {
			cout << i << endl;
			return 0;
		}
	}

	cout << "0" << endl;

	return 0;
}