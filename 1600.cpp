#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace::std;

typedef struct {
	int ck, cm, ch, cw;
} node;

int main() {
	int k;
	int w, h;
	int min = -1;

	cin >> k; // moves
	cin >> w >> h; // width, height

	int temp;
	vector<vector<int>> board(h, vector<int>(w, 0));
	vector<vector<vector<int>>> visit(h, vector<vector<int>> (w, vector<int> (k + 1, w + h)));
	int move[12][2] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
						{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
						{1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> temp;
			board[i][j] = temp;
		}
	}
	
	queue<node> moves;

	visit[0][0][0] = 1;
	moves.push({0, 0, 0, 0});
	int cw, ch, ck, cm;

	while (!moves.empty()) {
		ch = moves.front().ch;
		cw = moves.front().cw;
		ck = moves.front().ck;
		cm = moves.front().cm;


		if (ch == h - 1 && cw == w - 1) {
			int count = ck + cm;
			if (min > count || min == -1) {
				min = count;
			}
		}	
		else {
			for (int i = 0; i < 12; i++) {
				if (0 <= ch + move[i][0] && ch + move[i][0] < h &&
					0 <= cw + move[i][1] && cw + move[i][1] < w) {
					if (board[ch + move[i][0]][cw + move[i][1]] != 1) {
						if (i < 8 && ck < k && visit[ch + move[i][0]][cw + move[i][1]][ck + 1] > ck + cm + 1) {
							node temp = { ck + 1, cm, ch + move[i][0], cw + move[i][1]};
							moves.push(temp);
							visit[ch + move[i][0]][cw + move[i][1]][ck + 1] = ck + cm + 1;
						}
						else if (i >= 8 && visit[ch + move[i][0]][cw + move[i][1]][ck] > ck + cm + 1) {
							node temp = { ck, cm + 1, ch + move[i][0], cw + move[i][1]};
							moves.push(temp);
							visit[ch + move[i][0]][cw + move[i][1]][ck] = ck + cm + 1;
						}
					}
				}
			}
		}
		moves.pop();
	}

	cout << min << endl;

	return 0;
}