#include<iostream>

using namespace std;

#include<vector>

int main() {
	int T;
	cin >> T;
	while (T > 0) {
		int n;
		cin >> n;
		vector<int> all(n);
		for (int i(0); i < n; i++)
			cin >> all[i];

		long long k = all[0];
		for (int i(2); i < n; i++) {
			k *= all[i];
		}

		if (k%all[1] == 0)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}