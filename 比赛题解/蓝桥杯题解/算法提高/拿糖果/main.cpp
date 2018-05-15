#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#include <math.h>
#include <algorithm>
#include <queue>
#include <iomanip>
#define INF 0x3f3f3f3f
#define MAXN 100005
#define Mod 99999999
using namespace std;
bool notprime[MAXN];
int primes[700005]; //素数从i=1开始
void get_prime()
{
	notprime[1] = true;
	for (int i = 2; i<MAXN; ++i)
		if (!notprime[i])
		{
			primes[++primes[0]] = i;
			for (long long j = (long long)i*i; j<MAXN; j += i)
				notprime[j] = true;
		}
}
int dp[MAXN];
int main()
{
	get_prime();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= primes[0]; ++j)
		{
			if (primes[j]>sqrt(i))
				break;
			if (i%primes[j] == 0)
			{
				dp[i] = max(dp[i], dp[i - 2 * primes[j]] + primes[j]);
			}
		}
	}
	cout << dp[n];
	return 0;
}