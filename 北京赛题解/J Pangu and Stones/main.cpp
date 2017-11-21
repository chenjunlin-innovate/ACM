#include<stdio.h>  
#include<string>
#include<iostream>
#include<algorithm>  
using namespace std;
  
int a[105], sum[105][105];
long long  dp[105][105][105];
int main(void)
{
	int i, j, k, p, n, l, r;
	while (cin >> n >> l >> r)
	{
		for (i = 1; i <= n; i++)
			cin >> a[i];
		memset(dp, 62, sizeof(dp));
		for (i = 1; i <= n; i++)
		{
			sum[i][i - 1] = 0;
			for (j = i; j <= n; j++)
			{
				sum[i][j] = sum[i][j - 1] + a[j];
				dp[i][j][j - i + 1] = 0;
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = i; j <= n; j++)
				dp[i][j][j - i + 1] = 0;
		}
		for (p = 1; p <= n - 1; p++)
		{
			for (i = 1; i + p <= n; i++)
			{
				for (j = i; j <= i + p - 1; j++)
				{
					for (k = l - 1; k <= r - 1; k++)
						dp[i][i + p][1] = min(dp[i][i + p][1], dp[i][j][k] + dp[j + 1][i + p][1] + sum[i][i + p]);
				}
				for (j = 2; j <= p; j++)
				{
					for (k = i; k <= i + p - 1; k++)
						dp[i][i + p][j] = min(dp[i][i + p][j], dp[i][k][j - 1] + dp[k + 1][i + p][1]);
				}
			}
		}
		if (dp[1][n][1] == 4485090715960753726ll)
			cout << 0 << endl;
		else
			cout << dp[1][n][1] << endl;
	}
	return 0;
}