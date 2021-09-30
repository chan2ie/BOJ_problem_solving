#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main() {
	int n, h;

	cin >> n >> h;
	
	vector<int> top;
	vector<int> bottom;
	int temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (i % 2 == 0) {
			top.push_back(temp);
		}
		else {
			bottom.push_back(temp);
		}
	}
	
	sort(top.begin(), top.end());
	sort(bottom.begin(), bottom.end(), greater<int>());

	int cur_d = 1;
	int cur = n / 2;
	int min = n / 2;
	int count = 0;
	int t = 0;
	int b = 0;

	while (cur_d <= h) {
		while (t < top.size() && top[t] < cur_d) {
			cur--;
			t++;
		}

		while (b < bottom.size() && bottom[b] > h - cur_d) {
			cur++;
			b++;
		}

		if (min > cur) {
			min = cur;
			count = 1;
		}
		else if (min == cur) {
			count++;
		}
		cur_d++;
	}

	cout << min << " " << count << endl;
}