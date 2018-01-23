#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T>0)
	{
		int x;
		cin >> x;
		vector<int> all(1000);
		all[0] = x;
		all[1] = x / 2;
		int max;
		for (int i(0);; i++) {
			if (all[i] == 0) {
				max = i;
				break;
			}
			all[i + 1] += all[i] / (i + 2);
			all[i] = all[i] % (i + 2);
		}
		for (int i(max); i >= 0; i--) {
			for (int j(0); j < all[i]; j++)
				cout << i;
		}
		cout << endl;
		T--;
	}
}