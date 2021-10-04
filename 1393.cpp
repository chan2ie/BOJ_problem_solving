#include <iostream>

using namespace::std;

int main() {
	double xs, ys;
	double xe, ye, dx, dy;
	double xa, ya;

	cin >> xs >> ys;
	cin >> xe >> ye >> dx >> dy;

	// doesn't move
	if (dx == 0 && dy == 0) {
		cout << xe << " " << ye << endl;
	}
	// moves in x axis
	else if (dy == 0) {
		if ((xs - xe) / dx < 0) {
			cout << xe << " " << ye << endl;
		}
		else {
			cout << xs << " " << ye << endl;
		}

	}
	// moves in y axis
	else if (dx == 0) {
		if ((ys - ye) / dy < 0) {
			cout << xe << " " << ye << endl;
		}
		else {
			cout << int((ys - ye) / dy * dx + xe) << " " << ys << endl;
		}
		return 0;
	}
	// normal case
	else {
		xa = ((dx * xs + dy * ys) * dx + (dy * xe - dx * ye) * dy ) / (dx * dx + dy * dy);

		if ((xa - xe) / dx < 0) {
			cout << xe << " " << ye << endl;
		}
		else {
			ya = ye + ((xa - xe) / dx * dy);
			cout << xa << " " << ya << endl;
		}
	}

	return 0;
}