#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int> >all(m, vector<int>(n, 0));
	for (int i(0); i < m; i++) {
		for (int j(0); j < n; j++) {
			char x;
			cin >> x;
			if (x == '.')all[i][j] = 0;
			else if (x == '*')all[i][j] = -1;
			else all[i][j] = x-'0';
		}
	}
	for (int i(0); i < m; i++) {
		for (int j(0); j < n; j++) {
			if (all[i][j] == -1)continue;
			int count(0);
			if (i - 1 >= 0 && all[i - 1][j] == -1)count++;
			if (i + 1 < m && all[i + 1][j] == -1)count++;
			if (j - 1 >= 0 && all[i][j - 1] == -1)count++;
			if (j + 1 < n && all[i][j + 1] == -1)count++;
			if (i - 1 >= 0 && j - 1 >= 0 && all[i - 1][j - 1] == -1)count++;
			if (i + 1 < m && j - 1 >= 0 && all[i + 1][j - 1] == -1)count++;
			if (i - 1 >= 0 && j + 1 < n &&all[i - 1][j + 1] == -1)count++;
			if (i + 1 < m && j + 1 < n &&all[i + 1][j + 1] == -1)count++;

			if (count != all[i][j]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}	
	cout << "YES" << endl;
	return 0;
}