#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> q(n);
		for (int i(0); i < n; i++) {
			cin >> q[i];
		}
		int sum;
		cin >> sum;

		for (int i(0); i < n; i++) {
			for (int j(0); j < i; j++) {
				if (q[j] + q[i] == sum) {
					cout << j + 1 << ' ' << i + 1 << endl;
					goto LUCK;
				}
			}
		}
	LUCK:;
	}
}