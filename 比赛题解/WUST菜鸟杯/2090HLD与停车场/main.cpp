#include<iostream>
#include<vector>

using namespace std;

vector<vector<char> >map;

int main() {
	int m, n;
	while (cin >> m >> n) {
		map.clear();
		map.resize(m, vector<char>(n));
		for (int i(0); i < m; i++) {
			for (int j(0); j < n; j++) {
				cin >> map[i][j];
			}
		}

		int k; cin >> k;
		int sum(0);


		for (int i(0); i < m; i++) {
			for (int j(0); j < n; j++) {
				if (map[i][j] == '*') {
					int x = i, y = j;
					while (x >= 0 && y >= 0 && x < m&&y < n&&map[x][y] == '*') {
						map[x][y] = '.';
						y++;
					}
					y--;
					x++;
					while (x >= 0 && y >= 0 && x < m&&y < n&&map[x][y] == '*') {
						map[x][y] = '.';
						x++;
					}
					x--;
					y--;
					while (x >= 0 && y >= 0 && x < m&&y < n&&map[x][y] == '*') {
						map[x][y] = '.';
						y--;
					}
					y++;
					x--;
					while (x >= 0 && y >= 0 && x < m&&y < n&&map[x][y] == '*') {
						map[x][y] = '.';
						x--;
					}
					sum++;
				}
			}
		}
		if (sum >= k)cout << "ÎÚÑ»×ø·É»ú" << endl;
		else cout << "boy next door!" << endl;
	}
}