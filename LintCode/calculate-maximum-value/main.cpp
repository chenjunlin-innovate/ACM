#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int calcMaxValue(string &str) {
		if (str.empty())
			return 0;
		int sum = str[0] - '0';
		for (int i(1); i < str.size(); i++) {
			if ((str[i] - '0') + sum >(str[i] - '0') * sum)
				sum += (str[i] - '0');
			else 
				sum *= (str[i] - '0');
		}

		cout << sum << endl;
		return sum;
	}
};

int main() {
	string a;
	while (cin >> a) {
		Solution x;
		x.calcMaxValue(a);
	}
}
