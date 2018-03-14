#include<iostream>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		int max(0);
		int x;
		for (int i(0); i < n; i++) {
			cin >> x;
			if (x > max)max = x;
		}
		cout << max << endl;
	}
	return 0;
}