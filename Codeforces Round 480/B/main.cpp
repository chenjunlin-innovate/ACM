#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
int n, K;
char a[6][105];
int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = '.';
		}
	}
	cout<<"YES"<<endl;
	if (K % 2 == 0) {
		K /= 2;
		for (int i = 1; i <= K; ++i) {
			a[2][i + 1] = a[3][i + 1] = '#';
		}
	}
	else {
		if (n == 1) {
			a[2][2] = '#';
		}
		else if (K <= n - 2) {
			for (int i = 1, j = (n - K) / 2 + 1; i <= K; ++i, ++j) {
				a[3][j] = '#';
			}
		}
		else if (K == n) {
			for (int i = 1, j = 2; i <= n - 2; ++i, ++j) {
				a[3][j] = '#';
			}
			a[2][2] = a[2][n - 1] = '#';
		}
		else {
			for (int i = 1, j = 2; i <= n - 2; ++i, ++j) {
				a[3][j] = '#';
			}
			a[2][2] = a[2][n - 1] = '#';
			for (int i = 3, j = 1; i <= n - 2 && j <= K - n; ++i, ++j) {
				a[2][i] = '#';
			}
		}
	}
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= n; ++j) {
			putchar(a[i][j]);
		}
		cout<<endl;
	}
	return 0;
}