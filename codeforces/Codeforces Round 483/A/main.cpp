#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int n;
	while (cin>>n)
	{
		vector<int> num(n);
		for (int i(0); i < n; i++) {
			cin >> num[i];
		}
		sort(num.begin(), num.end());

		cout << num[(n - 1) / 2] << endl;
	}
}