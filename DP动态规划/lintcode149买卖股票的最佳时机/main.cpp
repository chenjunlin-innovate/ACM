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
		int min(0), max(0);
		int sum(0);
		for (int i(0); i < prices.size(); i++) {
			if (prices[i] < prices[min]) {
				min = i;
				max = i;
			}
			if (prices[i] > prices[max]) {
				max = i;
				if (prices[max] - prices[min] > sum)
					sum = prices[max] - prices[min];
			}
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