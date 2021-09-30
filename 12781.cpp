#include <iostream>
#include <vector>

using namespace ::std;

int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	float xp, yp;
	int d = 0;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	cin >> x4 >> y4;

	if (x1 == x2) {
		if (!(x3 == x4 && x3 == x1)) {
			xp = float(x1);
			yp = (y3 - y4) / float(x3 - x4) * (xp - x3) + y3;
		}
	}
	else if (x3 == x4) {
		xp = float(x3);
		yp = (y1 - y2) / float(x1 - x2) * (xp - x1) + y1;
	}
	else {
		d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
		if (d == 0) {
			cout << 0 << endl;
			return 0;
		}

		xp = float((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / d;
		yp = float((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / d;
	}
	// cout << "( " << xp << ", " << yp << " )" << endl;
	
	if ((xp == float(x1) && yp == float(y1)) ||
		(xp == float(x2) && yp == float(y2)) ||
		(xp == float(x3) && yp == float(y3)) ||
		(xp == float(x4) && yp == float(y4))) {
		cout << 0 << endl;
		return 0;
	}

	if (min(x1, x2) <= xp && max(x1, x2) >= xp && min(x3, x4) <= xp && max(x3, x4) >= xp &&
		min(y1, y2) <= yp && max(y1, y2) >= yp && min(y3, y4) <= xp && max(y3, y4) >= yp) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;

}