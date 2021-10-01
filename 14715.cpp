#include <iostream>
#include <queue>
#include <math.h>

using namespace ::std;

int main() {
	int k, count = 0;
	cin >> k;
	int a = 2;
	while (k > 1) {
		if (k % a == 0) {
			k /= a;
			count++;
		}
		else {
			a++;
			if (a > sqrt(k)) {
				count++;
				break;
			}
		}
	}
	int answer = 0;
	while (pow(2, answer) < count) {
		answer++;
	}
	cout << answer << endl;
	return 0;
}
	/* queue<pair<int, int>> slimes;

	slimes.push(make_pair(k, 0));

	int num, a, b;
	while (!slimes.empty()) {
		count = slimes.front().second;
		num = slimes.front().first;

		b = -1;
		a = 2;
		while (a <= sqrt(num)) {
			if (num % a == 0) {
				b = num / a;
			}
			a++;
		}
		if (b != -1) {
			a = num / b;
			cout << a << " " << b << endl;
			slimes.push(make_pair(a, count + 1));
			slimes.push(make_pair(b, count + 1));
		}
		slimes.pop();
	}
	
	cout << count << endl;

	return 0;
}
*/