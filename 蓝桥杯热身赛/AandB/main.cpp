#include<iostream>
#include<algorithm>

using namespace std;

int n, k;
int w[100001], v[100001];

double y[100001];

bool C(double x) {
	for (int i(0); i < n; i++) {
		y[i] = v[i] - x * w[i];
	}
	sort(y, y + n);

	double sum(0);
	for (int i(0); i < k; i++) {
		sum += y[n - i - 1];
	}

	return sum >= 0;
}

void solve() {
	double lb = 0, ub = 1000000000;
	for (int i(0); i < 100; i++) {
		double mid = (lb + ub) / 2;
		if (C(mid))lb = mid;
		else ub = mid;
	}

	printf("%.2f\n", ub);
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		for (int i(0); i < n; i++) {
			cin >> w[i] >> v[i];
		}
		solve();
	}
	return 0;
}