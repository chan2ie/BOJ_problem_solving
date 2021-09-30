#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace::std;

int main() {
	int d, n, min = 1000000001;

	stack<int> oven;
	queue<int> pizza;

	cin >> d >> n;

	int temp;

	for (int i = 0; i < d; i++) {
		cin >> temp;
		if (min > temp) {
			min = temp;
		}
		oven.push(min);
	}

	for (int i = 0; i < n; i++) {
		cin >> temp;
		pizza.push(temp);
	}

	while (!pizza.empty()) {
		if (oven.empty()) {
			cout << 0 << endl;
			return 0;
		}
		if (pizza.front() > oven.top()) {
			oven.pop();
			d--;
		}
		else {
			pizza.pop();
			oven.pop();
			d--;
		}
	}

	cout << oven.size() + 1 << endl;
	return 0;
}