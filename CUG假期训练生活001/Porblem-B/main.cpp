#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		map<int, int>all;
		int q = (n + 1) / 2;
		int ans;
		int k;
		for (int i(0); i < n; i++) {
			scanf("%d", &k);
			if (all[k] == 0) {
				all[k] = q;
			}
			all[k]--;
			if (all[k] == 0) {
				ans = k;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

