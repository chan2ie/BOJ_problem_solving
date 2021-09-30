#include <iostream>

using namespace::std;

int fib(int n) {
	if (n <= 0) return 0;
	else if (n <= 2) return 1;
	else return fib(n - 1) + fib(n - 2);
}

int main() {
	int d, k;
	int ka, kb;
	int a, b = 0;

	cin >> d >> k;

	ka = fib(d - 2);
	kb = fib(d - 1);

	do {
		b++;
		a = (k - kb * b) / ka;
	} while ((k - kb * b) % ka != 0 || b < a);

	cout << a << endl << b << endl;
}