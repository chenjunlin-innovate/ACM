#include<iostream>
#include<string>

using namespace std;

int main() {
	int n;
	string a;
	while (cin>>n>>a)
	{
		if (n == 1) {
			if (a[0] == '0')cout << "No" << endl;
			else cout << "Yes" << endl;
			continue;
		}
		int ok = 1;
		for (int i(0); i < n - 1; i++) {
			if (ok == 0)break;
			if (a[i] == '1'&&a[i + 1] == '1')ok = 0;
		}
		for (int i(0); i < n - 2; i++) {
			if (ok == 0)break;
			if (a[i] == '0'&&a[i + 1] == '0'&&a[i + 2] == '0')ok = 0;
		}
		if ((a[0] == '0'&&a[1] == '0') || (a[n - 1] == '0'&&a[n - 2] == '0'))ok = 0;
		if (ok)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}