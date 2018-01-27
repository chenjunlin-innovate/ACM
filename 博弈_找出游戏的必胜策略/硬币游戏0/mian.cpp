#include<iostream>
using namespace std;
bool x[100001];
int main() {
	int n;
	while (cin>>n)
	{
		for (int i(1); i <= n; i++) {
			if (i == 1 || i == 2)x[i] = 1;
			else x[i] = x[i - 1] ^ x[i - 2];
		}
		if (x[n])cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
}