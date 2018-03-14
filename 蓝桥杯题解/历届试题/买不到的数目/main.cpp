#include<iostream>
#include<vector>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	vector<bool>all(a*b + 1, 0);
	for (int i(0); i <= b; i++) {
		for (int j(0); j <= a; j++) {
			if(i * a + j * b<=a*b)	
				all[i * a + j * b] = 1;
		}
	}
	int max(0);
	int x = a * b + 1;
	for (int i(0); i < x; i++) {
		if (!all[i])max = i;
	}
	cout << max << endl;
	return 0;
}