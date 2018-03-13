#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int x, y;
	cin >> x;
	vector<int> all;
	for (int i(0); i < x; i++) {
		cin >> y;
		all.push_back(y);
	}
	sort(all.begin(), all.end());
	cout << all[0];
	for (int i(1); i < x; i++) {
		cout << " " << all[i] ;
	}
	return 0;
}