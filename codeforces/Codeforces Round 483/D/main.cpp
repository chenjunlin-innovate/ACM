#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int dp[5010][5010];

using namespace std;

int main() {
	int n;
	while (cin >> n)
	{
		for (int i(0); i < n; i++) {
			cin >> dp[0][i];
		}
		for (int i(1); i < n; i++) {
			for (int j(0); j <= n - i; j++) {
				dp[i][j] = dp[i-1][j] ^ dp[i-1][j + 1];
			}
		}

		for (int i(1); i < n; i++) {
			for (int j(0); j < n - i; j++) {
				dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i - 1][j + 1] });
			}
		}

		int q;
		cin >> q;
		for (int i(0); i < q; i++) {
			int l, r;
			cin >> l>> r;
			cout << dp[r - l][l - 1] << endl;
		}
	}
}