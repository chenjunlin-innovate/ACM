#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

struct point {
	int x;
	int y;
};

vector<int>num;

int main() {
	for (int i(0); i < 500; i++) {
		num.push_back(pow(i, 2));
	}
	int n;
	while (cin >> n) {
		point q;
		vector<point>all;
		for (int i(0); i < n; i++) {
			cin >> q.x >> q.y;
			all.push_back(q);
		}
		int sum(0);
		for (int i(0); i < n; i++) {
			for (int j(i + 1); j < n; j++) {
				sum += num[abs(all[i].x - all[j].x)] + num[abs(all[i].y - all[j].y)];
			}
		}
		cout << sum << endl;
	}
}