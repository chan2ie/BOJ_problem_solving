#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <set>

using namespace ::std;

int main() {
	int n, q;

	cin >> n >> q;

	vector<vector<pair<int, int>>> vnet(n + 1, vector<pair<int, int>> ());
		
	int q1, q2, r;
	
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &q1, &q2, &r);

		vnet[q2].push_back(make_pair(q1, r));
		vnet[q1].push_back(make_pair(q2, r));
	}
	
	int k, v;
	vector<int> ks;
	vector<int> vs;

	for (int i = 0; i < q; i++) {
		scanf("%d %d", &k, &v);
		ks.push_back(k);
		vs.push_back(v);
	}

	vector<int> visit(n + 1, -1);
	queue<pair<int, int>> search;
	int answer;

	for (int i = 0; i < q; i++) {
		for (int j = 0; j < n + 1; j++) {
			visit[j] = -1;
		}
		visit[vs[i]] = 1;

		answer = 0;

		// cout << endl;

		search.push(make_pair(vs[i], ks[i]));
		
		while (!search.empty()) {
			// cout << search.front().first << " " << search.front().second << endl;
			for (auto p : vnet[search.front().first]) {
				if (visit[p.first] == -1 && p.second >= ks[i]) {
					visit[p.first] = 1;
					search.push(make_pair(p.first, min(search.front().second, p.second)));
				}
			}
			if (search.front().second >= ks[i]) {
				answer++;
			}
			search.pop();
		}

		cout << answer - 1<< endl;
	}

	return 0;
}