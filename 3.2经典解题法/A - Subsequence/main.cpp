#include<iostream>
#include<algorithm>

using namespace std;

int n, S;
int a[100001];

void solve() {
	int res = n + 1;
	int s = 0, t = 0, sum = 0;
	while (1) {
		while (t < n&&sum < S)
			sum += a[t++];
		if (sum < S)break;
		res = min(res, t - s);
		sum -= a[s++];
	}
	if (res > n)
		res = 0;

	printf("%d\n", res);
}

int main() {
	int x;
	cin >> x;
	while (x--) {
		cin >> n >> S;
		for (int i(0); i < n; i++)
			cin >> a[i];

		solve();
	}
}