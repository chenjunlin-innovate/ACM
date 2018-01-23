#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T > 0) {
		int n;
		cin >> n;
		long long p = 0;
		long long q = 1;
		long long sum;
		for (int i(0); i < n; i++) {
			sum = p + q;
			p = q;
			q = sum;
		}
		cout << sum << endl;
		T--;
	}
}