#include<iostream>

using namespace std;

int solo(int x) {
	int a(1), b(1), c(1);
	for (int i(3); i <= x; i++) {
		c = a + b;
		if (c > 10007)
			c -= 10007;
		a = b;
		b = c;
	}
	return c;
}

int main() {
	int x;
	cin >> x;
	cout << solo(x) << endl;
	return 0;
}