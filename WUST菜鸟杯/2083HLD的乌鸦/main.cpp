#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n) {
		vector<int> all(n);
		for (int i(0); i < n; i++)
			cin >> all[i];

		sort(all.begin(), all.end());

 		int x1 = m;
		int x2 = 0;
		int x3 = 0;

		for (int i(n-1); i >=0; i++) {
			int q = all[i] / 4;
 			if (x2 >= q) {
				x2 -= q;
			}
			else {
				x2 -= q;
				x1 += x2;
				x2 = 0;
			}

			int p = all[i] % 4;
			if (x3 - p < 0) {
				x1--;
				x3 += 4 - p;
				x2++;
			}
			else {
				x3 -= p;
			}
		}
		if (x1 >= 0)cout << "YES" << endl;
		else cout << "NO" << endl;

	}
}