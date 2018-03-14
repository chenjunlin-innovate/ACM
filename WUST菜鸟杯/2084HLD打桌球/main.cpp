#include<iostream>

using namespace std;

int main() {
	int a, b;
	int n;
	cin >> n;
	for (int i(0); i < n; i++) {
		cin >> a >> b;
		double q = (double)b / (2.0 * a);
		if (q - (int)q > 0.5)
			cout << "Case " << i + 1 << ": " << b / (2 * a) + 1 << endl;
		else cout << "Case " << i + 1 << ": " << b / (2 * a) << endl;
	}
	return 0;
}