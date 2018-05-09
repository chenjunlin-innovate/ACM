#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	string a;
	cin >> a;
	int l = 0;
	int m = 0;
	for (int i(0); i < a.size(); i++) {
		if (a[i] == 'o')l++;
		else m++;
	}
	if (l == 1 || l == 0 || m == 0) { 
		cout << "YES" << endl;
		return 0;
	}
	if (m % l != 0)
		cout << "NO" << endl;
	else 
		cout << "YES" << endl;
	return 0;
}