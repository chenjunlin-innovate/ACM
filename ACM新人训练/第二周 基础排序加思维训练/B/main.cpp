#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> a = { "Power","Time","Space","Soul","Reality","Mind" };
bool b[6] = { 0,0,0,0,0,0 };

int main() {
	int n;
	while (cin>>n)
	{
		string x;
		for (int i(0); i < 6; i++)b[i] = 0;
		for (int i(0); i < n; i++) {
			cin >> x;
			if (x == "Power" || x == "purple")b[0] = 1;
			else if (x == "Time" || x == "green")b[1] = 1;
			else if (x == "Space" || x == "blue")b[2] = 1;
			else if (x == "Soul" || x == "orange")b[3] = 1;
			else if (x == "Reality" || x == "red")b[4] = 1;
			else if (x == "Mind" || x == "yellow")b[5] = 1;
		}
		int ans = 0;
		for (int i(0); i < 6; i++)
			if (b[i] == 0)ans++;
		cout << ans << endl;
		for (int i(0); i < 6; i++)
			if (b[i] == 0)cout << a[i] << endl;
	}
	return 0;
}