#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(int a, int b) {
	if (a > 98765)return false;
	bool x[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i(0); i < 5; i++) {
		if (x[a % 10])
			return false;
		else
			x[a % 10] = true;

		a /= 10;
	}

	for (int i(0); i < 5; i++) {
		if (x[b % 10])
			return false;
		else
			x[b % 10] = true;

		b /= 10;
	}
	return true;
}

int main() {
	int n;
	int t(0);
	while (cin>>n)
	{
		if (n == 0)break;
		if(t++)cout << endl;
		int flag = 0;
		for (int i(1234); i < 50000; i++) {
			if (check(i*n, i)) {
				if (i*n < 10000)cout << 0;
				cout << i * n << " / ";
				if (i < 10000)cout << 0;
				cout << i << " = " << n << endl;
				flag++;
			}
		}
		if(flag==0)
			cout << "There are no solutions for " << n << '.' << endl;
	}
}