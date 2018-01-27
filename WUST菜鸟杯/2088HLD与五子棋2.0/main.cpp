#include<iostream>
using namespace std;
#include<string>

int main() {
	int n;
	string s;
	while (cin >> n >> s) {
		if (n % 2 == 0)cout << "draw" << endl;
		else cout << s << endl;
	}
	return 0;
}