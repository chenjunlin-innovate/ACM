#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >all;
vector<bool>check(8, 0);
int k,n;
int sum;
void dfs(int i,int x) {
	if (x == k) {
		sum++;
		return;
	}
	if (i >= n)
		return;
	for (int j(0); j < all[i].size(); j++) {
		if (!check[all[i][j]]) {
			check[all[i][j]] = 1;
			dfs(i + 1, x + 1);
			check[all[i][j]] = 0;
		}
	}
	dfs(i + 1, x);
}

int main() {
	while (cin>>n>>k)
	{
		if (n == -1 && k == -1)
			break;
		all.clear();
		sum = 0;
		all.resize(n);
		char qq;
		for (int i(0); i < n; i++) {
			for (int j(0); j < n; j++) {
				cin >> qq;
				if (qq == '#')all[i].push_back(j);
			}
		}
		dfs(0, 0);
		cout << sum << endl;
	}
}