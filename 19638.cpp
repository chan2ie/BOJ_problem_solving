#include <iostream>
#include <queue>

using namespace::std;

int main() {

	int n, centi, count, temp;
	priority_queue<int> giants;
	
	cin >> n >> centi >> count;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		giants.push(temp);
	}

	int i;
	for (i = 0; i < count; i++) {
		if (giants.empty() || giants.top() < centi) {
			break;
		}
		temp = giants.top();
		if (temp == 1) break;
		giants.pop();
		if(temp/2 >= centi)
			giants.push(temp / 2);
	}
	if (!giants.empty() && giants.top() >= centi) {
		cout << "NO" << endl << giants.top() << endl;
	}
	else {
		cout << "YES" << endl << i << endl;
	}
	return 0;
}