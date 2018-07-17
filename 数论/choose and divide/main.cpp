#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stdio.h>

using namespace std;

vector<int>primes;
vector<int>e(10000);

void add_integer(int n, int d) {
	for (int i(0); i < primes.size(); i++) {
		while (n%primes[i]==0)
		{
			n /= primes[i];
			e[i] += d;
		}
		if (n == 1)break;
	}
}

void add_factorial(int n, int d) {
	for (int i(1); i <= n; i++) {
		add_integer(i, d);
	}
}


void init() {
	primes.push_back(2);
	for (int i(3); i < 10001; i++) {
		int ok = 1;
		for (int j(0); j < primes.size(); j++) {
			if (i%primes[j] == 0) {
				ok = 0;
				break;
			}
		}
		if (ok)
			primes.push_back(i);
	}
}

int main() {
	int p, q, r, s;
	init();
	while (cin>>p>>q>>r>>s)
	{
		e.clear();
		e.resize(10000, 0);
		add_factorial(p, 1);
		add_factorial(q, -1);
		add_factorial(p - q, -1);
		add_factorial(r, -1);
		add_factorial(s, 1);
		add_factorial(r - s, 1);

		double ans = 1;
		for (int i(0); i < primes.size(); i++) {
			ans *= pow(primes[i], e[i]);
		}
		printf("%.5lf\n", ans);
	}

	return 0;
}