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
	int maxProfit(vector<int> &prices) {
		if (prices.size() == 0)
			return 0;
		vector<int>FirstBuy(prices.size());
		vector<int>FirstSell(prices.size(), 0);
		vector<int>SecoundBuy(prices.size());
		vector<int>SecoundSell(prices.size(), 0);

		FirstBuy[0] = -prices[0];
		SecoundBuy[0] = -prices[0];

		for (int i(1); i < prices.size(); i++) {
			FirstBuy[i] = max(FirstBuy[i - 1], -prices[i]);
			FirstSell[i] = max(FirstSell[i - 1], prices[i] + FirstBuy[i - 1]);
			SecoundBuy[i] = max(SecoundBuy[i - 1], FirstSell[i - 1] - prices[i]);
			SecoundSell[i] = max(SecoundSell[i - 1], prices[i] + SecoundBuy[i]);
		}
		return SecoundSell[prices.size() - 1];
	}
};

int main() {
	int n;
	while (cin >> n) {
		vector<int>all(n);
		for (int i(0); i < n; i++) {
			cin >> all[i];
		}
		Solution x;
		cout << x.maxProfit(all) << endl;
	}
}