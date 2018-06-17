#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	int l, r, a;
	while (cin >> l >> r >> a) {
		int ans(0);
		if (a > abs(l - r)) {
			ans += max(l, r) * 2;
			ans += (a - abs(l - r)) / 2 * 2;
		}
		else {
			ans += (min(l, r) + a) * 2;
		}
		cout << ans << endl;
	}
}