#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int n;
	while (cin>>n)
	{
		vector<long long> num(n+5, 0);
		cin >> num[1];
		for (int i(2); i <= n; i++) {
			long long a;
			cin >> a;
			num[i] = num[i - 1] ^ a;
		}
		int m;
		cin >> m;
		for (int i(0); i < m; i++) {
			int a, b;
			cin >> a >> b;
			cout << (num[a-1] ^ num[b]) << endl;
		}

	}
}