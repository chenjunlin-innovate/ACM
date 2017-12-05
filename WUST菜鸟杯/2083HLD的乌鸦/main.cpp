#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int m, n;
	int qqq = 0;
	while (cin >> m >> n) {
		qqq++;
		vector<int> all(n);
		
		for (int i(0); i < n; i++) {
			cin >> all[i];
		}
		sort(all.begin(), all.end());
		int x = all[n-1] / 4;
		if (all[n-1] % 4)x++;
		if (x > m) {
			cout << "Case "<<qqq<<": "<<"NO" << endl;
			continue;
		}
		int sum(0);
		for (int i(0); i < n; i++)
			sum += all[i];

		if(sum>(m*8))
			cout << "Case " << qqq << ": " << "NO" << endl;
		else cout << "Case " << qqq << ": " << "YES" << endl;
		

	}
}