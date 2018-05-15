#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int t(0);
	while (cin >> n) {
		t++;
		vector<int> num(n, 0);
		for (int i(0); i < n; i++)
			cin >> num[i];
		long long ans = 0;
		for (int i(0); i < n; i++) {
			for (int j(i); j < n; j++) {
				long long k = 1;
				for (int l(i); l <= j; l++) {
					k *= num[l];
				}
				ans = max(ans, k);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", t, ans);
	}
}