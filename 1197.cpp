#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

// 트리에는 사이클이 없다,,^^,,

using namespace::std;
	
struct compare {
	bool operator()(vector<int> a, vector<int> b) {
		return a[2] > b[2];
	}
};

int main() {
	int v, e;
	int n1, n2, w;
	int answer = 0;
	vector<int> con_set;
	priority_queue<vector<int>, vector<vector<int>>, compare> edges;

	scanf("%d %d", &v, &e);

	for (int i = 0; i < v; i++) {
		con_set.push_back(i);
	}

	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &n1, &n2, &w);
		vector<int> tmp = { n1 - 1, n2 - 1, w };
		edges.push(tmp);
	}

	while (!edges.empty()) {
		if (con_set[edges.top()[0]] != con_set[edges.top()[1]]) {
			answer += edges.top()[2];
			int tmp = con_set[edges.top()[1]];
			con_set[edges.top()[1]] = con_set[edges.top()[0]];
			for (int i = 0; i < v; i++) {
				if (con_set[i] == tmp) {
					con_set[i] = con_set[edges.top()[0]];
				}
			}
		}
		edges.pop();
	}

	cout << answer << endl;

	return 0;
}