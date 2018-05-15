#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	while (cin>>n)
	{
		vector<pair<int, int>>all;
		for (int i(n + 1); i <= 2*n; i++) {
			if (i*n % (i - n) == 0) {
				all.push_back(pair<int, int>(i*n / (i - n), i));
			}
		}
		cout << all.size() << endl;
		for (int i(0); i < all.size(); i++) {
			cout << "1/" << n << " = " << "1/" << all[i].first << " + " << "1/" << all[i].second << endl;
		}
	}
}