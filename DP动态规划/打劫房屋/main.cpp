#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	long long houseRobber(vector<int> &A) {
		int x = A.size();
		vector<long long> b;
		if (x == 0)return 0;
		if (x == 1)return A[0];
		for (int i(0); i < x-1; i++) {
			if (i == 0)b.push_back(A[0]);
			else if (i == 1)b.push_back(max(A[0], A[1]));
			else {
				b.push_back(max(b[i - 1], b[i - 2] + A[i]));
			}
		}

		vector<long long> c;
		c.push_back(0);
		for (int i(1); i < x; i++) {
			if (i == 1)c.push_back(A[1]);
			else if (i == 2)c.push_back(max(A[1], A[2]));
			else {
				c.push_back(max(c[i - 1], c[i - 2] + A[i]));
			}
		}
		return max(c[x - 1], b[x - 2]);
	}
};


int main() {
	int x;
	vector<int>k;
	while (cin >> x)
		k.push_back(x);
	Solution a;
	a.houseRobber(k);
}