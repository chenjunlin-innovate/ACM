#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int n;
	while (cin>>n)
	{
		vector<int>all(n / 2, 0);
		for (int i(0); i < n / 2; i++) {
			cin >> all[i];
		}
		sort(all.begin(), all.end());
		int sum1(0);
		int sum2(0);

		for (int i(1); i <= n; i += 2) {
			sum1 += abs(all[i / 2] - i);
			sum2 += abs(all[i / 2] - (i + 1));
		}

		cout << min(sum1, sum2) << endl;
	}

	return 0;
}