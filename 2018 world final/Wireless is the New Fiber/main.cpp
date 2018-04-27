#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
const int maxn = 2e6 + 10;
int u[maxn], v[maxn];
LL st[maxn], ed[maxn];
double p[maxn];
vector<pii> vec;
map<LL, double> f[maxn];
map<LL, double> ::iterator it;
vector<int> G[maxn];

int main() {
	int m, n;
	LL k;
	scanf("%d %d %lld", &m, &n, &k);
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %lld %lld %lf", u + i, v + i, st + i, ed + i, p + i);
		if (u[i] == 1 || ed[i] > k) { m--; i--; continue; }
		vec.push_back(pii(st[i], u[i]));
		vec.push_back(pii(ed[i], v[i]));
	}
	vec.push_back(pii(k + 1, 1));
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 1; i <= m; ++i) {
		int x = lower_bound(vec.begin(), vec.end(), pii(st[i], u[i])) - vec.begin();
		G[x].push_back(i);
	}
	for (int i = vec.size() - 1; i >= 0; i--) {
		int x = vec[i].second;
		LL now = vec[i].first;
		double pre = x == 1 ? 1 : 0;
		if (x != 1) {
			it = f[x].upper_bound(now);
			if (it != f[x].end()) pre = (*it).second;
		}
		double M = pre;
		for (int j = 0; j < G[i].size(); ++j) {
			int y = G[i][j];
			it = f[v[y]].upper_bound(ed[y]);
			if (it == f[v[y]].end()) continue;
			M = max(M, p[y] * (*it).second + (1 - p[y]) * pre);
		}
		f[x][now] = M;
	}
	it = f[0].begin();
	printf("%.10f\n", (*it).second);
	return 0;
}