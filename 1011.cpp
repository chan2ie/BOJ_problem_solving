#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace::std;

int solution(int distance) {
	int answer = 0;
	int sqr;

	sqr = int(sqrt(distance));

	if (distance == pow(sqr, 2)) answer = sqr * 2 - 1;
	else if (distance <= sqr * (sqr + 1)) answer = sqr * 2;
	else answer = sqr * 2 + 1;

	return answer;
}

int main() {
	int repeat, x, y;
	vector<int> input;

	cin >> repeat;
	for (int i = 0; i < repeat; i++) {
		scanf_s("%d %d", &x, &y);
		
		input.push_back(y - x);
	}

	for (auto i : input) cout << solution(i) << endl;

	return 0;
}