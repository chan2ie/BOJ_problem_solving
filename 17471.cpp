#include <iostream>
#include <vector>
#include <queue>

using namespace::std;

int is_connected(vector<int> nodes) {

}

int main() {
	int n, sum = 0;
	cin >> n;
	vector<int> people(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> people[i];
		sum += people[i];
	}

	vector<vector<int>> connected(n, vector<int>(n, 0));
	int temp;
	for (int i = 0; i < n; i++) {
		int n2;
		cin >> n2;
		for (int j = 0; j < n2; j++) {
			cin >> temp;
			connected[i][temp] = 1;
		}
	}



}