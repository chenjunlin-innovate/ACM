#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int m, n, l;
	while (cin >> m >> n >> l)
	{
		int q = m * n;
		vector<int>all(q);
		for (int i(0); i < q; i++) {
			cin >> all[i];
		}
		sort(all.begin(), all.end());
		int max(0);
		for (int i(0); i < q; i++) {
			if (all[i] - all[0] <= l)
				max = i;
			else
				break;
		}
		if (max < m - 1) {
			cout << 0 << endl;
			continue;
		}
		int sum(0);
		int p = q - 1;
		if (n != 1) {
			int l = (q - max - 1) / (n - 1);
			p = max + (q - max - 1 - (q - max - 1) / (n - 1) *(n - 1)) - (n - 1) - l;
			for (int i(0); i < l; i++) {
				sum += all[max - i];
			}
		}
		for (int i(p); i >= 0; i -= n) {
			sum += all[i];
		}
		cout << sum << endl;
	}

	return 0;
}