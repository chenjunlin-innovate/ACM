#include<iostream>
#include<algorithm>
using namespace std;

long long quick_mod(long long a, long long b, long long mod) {
	long long ans = 1;
	while (b!=0)
	{
		if (b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b = b >> 1;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		int x, y;
		cin >> x >> y;
		int ans = 0;
		for (int i(0); i < y; i++) {
			int p, q;
			cin >> p >> q;
			ans = (ans + quick_mod(p, q, x)) % x;
		}
		cout << ans << endl;
	}
}