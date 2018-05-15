#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum(24);
	if (n == 1)
		cout << 2 << endl;
	else {
		for (int i(1); i < n; i++) {
			sum *= 4;
			sum %= 1000000007;
		}
		cout << sum << endl;
	}
	return 0;
}