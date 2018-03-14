#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:

	/*
	* @param nums1: an integer array
	* @param nums2: an integer array
	* @return: an integer array
	*/
	vector<int> intersection(vector<int> nums1, vector<int> nums2) {
		map<int, int>x;
		vector<int> nums3;
		for (int i(0); i < nums1.size(); i++)
			x[nums1[i]]++;
		for (int i = 0; i < nums2.size(); i++)
			if (x[nums2[i]]) {
				nums3.push_back(nums2[i]);
				x[nums2[i]]--;
			}

		return nums3;
	}
};