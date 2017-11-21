#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<vector<char>> p(n, vector<char>(n));
		for (int i(0); i < n; i++) {
			for (int j(0); j < n; j++) {
				cin >> p[i][j];
			}
		}
		//读入原矩阵

		int x(0), y(0);
		int q = n*n;
		bool kkk = 1;
		string xyz;
		for (int i(0); i < q; i++) {
			xyz += p[y][x];
			if (y == 0 && kkk == 1) {
				if (x == n - 1)y++;
				else x++;
				kkk = 0;
				continue;
			}
			else if (x == n - 1 && kkk == 1) {
				y++; kkk = 0;
				continue;
			}
			else if (x == 0 && kkk == 0) {
				if (y == n - 1)x++;
				else y++;
				kkk = 1;
				continue;
			}
			else if (y == n - 1 && kkk == 0) {
				x++;
				kkk = 1;
				continue;
			}
			if (kkk) {
				x++; y--;
			}
			else {
				x--; y++;
			}
		}
		//将原矩阵处理成字符串

		vector<vector<char>> lll(n, vector<char>(n));
		x = 0; y = 0;
		int b = -1;
		int j, k, i;
		for (i = 0; i<n / 2; i++)
		{
			for (j = i; j < n - i; j++) {
				lll[i][j] = xyz[++b];
			}
			for (k = i + 1, j--; k < n - i; k++) {
				lll[k][j] = xyz[++b];
			}
			for (j = --k, j--; j >= i; j--) {
				lll[k][j] = xyz[++b];
			}
			for (k--; k > i; k--) {
				lll[k][i] = xyz[++b];
			}
		}
		if (n % 2)
			lll[i][i] = xyz[++b];
		//将字符串旋转存入矩阵
		for (int i(0); i < n; i++) {
			for (int j(0); j < n; j++) {
				cout << lll[i][j];
			}
			cout << endl;
		}
		//输出旋转后矩阵
	}
}