#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T > 0) {
		int a, b;
		cin >> a >> b;
		vector<bool>all(1001, 1);
		for (int i(1);; i++) {
			if (a*i > 1000)break;
			all[a*i] = 0;
		}
		for (int i(1);; i++) {
			if (b*i > 1000)break;
			all[b*i] = 0;
		}
		while (a > 0) {
			int q = a % 10;
			a /= 10;
			for (int i(1);; i++) {
				
			}
		}
		T--;
	}
}