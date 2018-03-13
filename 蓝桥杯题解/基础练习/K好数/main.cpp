#include<vector>
#include<iostream>

using namespace std;

int main(){
	int x, y;
	cin >> x >> y;
	vector<vector<int> >all(y, vector<int>(x));
	for (int i(0); i < x; i++) {
		all[0][i] = 1;
	}
	for (int i(1); i < y; i++) {
		for (int j(0); j < x; j++) {
			for (int q(0); q < x; q++) {
				if (j != q - 1 && j != q + 1) {
					all[i][j] += all[i - 1][q];
					all[i][j] %= 1000000007;
				}
			}
		}
	}
	int sum(0);
	for (int i(1); i < x; i++) {
		sum += all[y - 1][i];
		sum %= 1000000007;
	}
	cout << sum << endl;
	return 0;
}