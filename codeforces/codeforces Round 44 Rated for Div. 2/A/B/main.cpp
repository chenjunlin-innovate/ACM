#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int m, n;
	while (cin>>m>>n)
	{
		vector<int>num(n,0);
		vector<string>all(m);
		for (int i(0); i < m; i++) {
			cin >> all[i];
			for (int j(0); j < n; j++) {
				if (all[i][j] == '1')
					num[j]++;
			}
		}

		int ok = 0;

		for (int i(0); i < m; i++) {
			for (int j(0); j < n; j++) {
				if (all[i][j] == '1' && num[j] < 2) {
					break;
				}
				else {
					if (j == n - 1)ok = 1;
				}
			}
			if (ok == 1)break;
		}

		if (ok == 1)cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}