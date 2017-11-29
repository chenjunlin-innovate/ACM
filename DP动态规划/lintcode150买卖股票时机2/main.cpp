#include<iostream>
#include<vector>

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
		int sum(0);
		for (int i(1); i < prices.size(); i++) {
			if (prices[i-1] < prices[i])
				sum += prices[i] - prices[i - 1];
		}
		return sum;
	}
};
int main() {
	int n;
	while (cin >> n) {
		vector<int> all(n);
		for (int i(0); i < n; i++)
			cin >> all[i];
		Solution x;
		cout << x.maxProfit(all) << endl;
	}
}