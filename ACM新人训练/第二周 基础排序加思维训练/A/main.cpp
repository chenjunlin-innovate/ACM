#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

struct score {
	string m_name;
	int m_score;
};

vector<score> ip(10000);
vector<score> np(10000);
vector<int> check(10000);

bool cmp(int x, int y) {
	if (ip[x].m_score != ip[y].m_score)
		return ip[x].m_score > ip[y].m_score;
	else return x < y;
}

int main() {
	int n;
	while (cin >> n)
	{
		for (int i(0); i < n; i++)check[i] = i;
		for (int i(0); i < n; i++) {
			cin >> ip[i].m_name >> ip[i].m_score;
		}
		for (int i(0); i < n; i++) {
			cin >> np[i].m_name >> np[i].m_score;
		}
		sort(check.begin(), check.begin() + n, cmp);
		int ok = 0;
		for (int i(0); i < n; i++) {
			if (ip[check[i]].m_name != np[i].m_name) {
				ok = 1;
			}
			if (ip[check[i]].m_score != np[i].m_score) {
				ok = 2;
				break;
			}
		}
		if (ok == 0) {
			cout << "Right" << endl;
			continue;
		}
		if (ok == 1) {
			cout << "Not Stable" << endl;
		}
		if (ok == 2) {
			cout << "Error" << endl;
		}
		for (int i(0); i < n; i++) {
			cout << ip[check[i]].m_name << " " << ip[check[i]].m_score << endl;
		}
	}
	return 0;
}