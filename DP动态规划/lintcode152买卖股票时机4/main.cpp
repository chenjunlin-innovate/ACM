#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	/*
	* @param prices: Given an integer array
	* @return: Maximum profit
	*/
	int maxProfit(int k,vector<int> &prices) {
		if (prices.size() == 0)
			return 0;
		if (k >= prices.size()) {
			int sum(0);
			for (int i(1); i < prices.size(); i++) {
				if (prices[i - 1] < prices[i])
					sum += prices[i] - prices[i - 1];
			}
			return sum;
		}
		vector<vector<int>>Buy(k, vector<int>(prices.size(),-prices[0]));
		vector<vector<int>>Sell(k, vector<int>(prices.size(), 0));


		for (int i(1); i < prices.size(); i++) {
			for (int j(0); j < k; j++) {
				if (j == 0)
					Buy[j][i] = max(Buy[j][i - 1], -prices[i]);
				else
					Buy[j][i] = max(Buy[j][i - 1], Sell[j - 1][i - 1] - prices[i]);
				Sell[j][i] = max(Sell[j][i - 1], prices[i] + Buy[j][i]);
			}
		}
		return Sell[k - 1][prices.size() - 1];
	}
};

int main() {
	int k, n;
	while (cin >> n >> k) {
		vector<int>all(n);
		for (int i(0); i < n; i++) {
			cin>>all[i];
		}
		Solution x;
		cout << x.maxProfit(k, all) << endl;
	}
}