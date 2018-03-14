#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;


int main() {
	string all;
	cin >> all;
	vector<char> x(105);
	int count(-1);
	for (int i(0); i < all.size(); i++) {
		if (count >= 0) {
			if (x[count] == 'o'&&all[i] == 'o') {
				if (count >= 1 && x[count - 1] == 'O')
					count -= 2;
				else x[count] = 'O';
			}
			else if(x[count] == 'O'&&all[i] == 'O') {
				count--;
			}
			else {
				count++;
				x[count] = all[i];
			}
		}
		else {
			count++;
			x[count] = all[i];
		}
	}
	for (int i(0); i <= count; i++) {
		cout << x[i];
	}
	return 0;
}