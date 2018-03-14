#include<map>
#include<set>
#include<algorithm>
#include<iostream>

#pragma warning(disable:4996)

using namespace std;

int p;
int MAX[1000010];

void solve() {
	set<int> all;
	for (int i(0); i < p; i++)
		all.insert(MAX[i]);

	int n = all.size();

	int s = 0, t = 0, num = 0;
	map<int, int>count;
	int res = p;
	while (1) {
		while (t<p&&num<n)
			if (count[MAX[t++]]++ == 0)
				num++;
		if (num < n)break;
		res = min(res, t - s);
		if (--count[MAX[s++]] == 0)
			num--;
	}
	printf("%d\n", res);
}

int main() {
	while (cin >> p) {
		for (int i(0); i < p; i++)
			scanf("%d", &MAX[i]);

		solve();
	}
}