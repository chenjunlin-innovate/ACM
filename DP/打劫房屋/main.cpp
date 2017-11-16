#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	long long houseRobber(vector<int> &A) {
		int x = A.size();
		vector<long long> b;
		if (x== 0)return 0;
		for (int i(0); i < x; i++) {
			if (i == 0)b.push_back(A[0]);
			else if (i == 1)b.push_back(max(A[0], A[1]));
			else {
				b.push_back(max(b[i - 1], b[i - 2] + A[i]));
			}
		}
		return b[x - 1];
	}
};
