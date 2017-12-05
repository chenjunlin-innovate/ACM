#include<iostream>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		double x = 360.0 / (180 - n);
		if (x - (int)x == 0 && n != 0)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}