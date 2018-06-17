#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main() {
	int T;
	map<string, int> findmax;
	map<string, int> findmax2;
	vector<pair<string, int> >alldata;
	cin >> T;
	while (T--)
	{
		string a;
		int b;
		cin >> a >> b;
		findmax[a] += b;
		alldata.push_back({ a,b });
	}
	map<string, int>::iterator x;
	int max1(-999999999);
	for (x = findmax.begin(); x != findmax.end(); x++)
		max1 = max(x->second, max1);
	for (int i(0); i < alldata.size(); i++) {
		findmax2[alldata[i].first] += alldata[i].second;
		if (findmax2[alldata[i].first] >= max1&&findmax[alldata[i].first]==max1) {
			cout << alldata[i].first << endl;
			break;
		}
	}
	return 0;
}


