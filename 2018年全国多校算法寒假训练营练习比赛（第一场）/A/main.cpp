#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n) 
	{
		vector<int>all_x(m);
		vector<vector<int>>all_y(m);
		vector<double>all(1001, 0);
		for (int i(0); i < m; i++) 
		{
			int q;
			cin >> q;
			all_x[i] = q;
			int p;
			cin >> p;
			for (int j(0); j < p; j++) 
			{
				int x;
				cin >> x;
				all_y[i].push_back(x);
			}
		}
		for (int i(0); i < n; i++) 
		{
			int p;
			double q;
			cin >> p >> q;
			if (all[p] < q)
				all[p] = q;
		}
		double max(0);
		for (int i(0); i < m; i++) 
		{
			double sum(1);
			for (int j(0); j < all_y[i].size(); j++) 
			{
				sum += all[all_y[i][j]];
			}
			sum *= all_x[i];
			if (sum > max)
				max = sum;
		}
		cout << fixed << setprecision(4) << max << endl;
	}
	return 0;
}