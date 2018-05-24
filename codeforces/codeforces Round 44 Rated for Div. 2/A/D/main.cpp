#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	long long m, n;
	while (cin >> m >> n)
	{
		int sum(0);
		if (m > n*(n + 1) / 2) {
			sum += (m - n * (n + 1) / 2) / n;
			if ((m - n * (n + 1) / 2) - (m - n * (n + 1) / 2) / n * n != 0)sum++;
		}
		sum += n;
	}

	return 0;
}