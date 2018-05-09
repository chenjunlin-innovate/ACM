#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 10;
typedef pair<int, int> pii;
int deg[maxn];			//´æ´¢Á¬½ÓÊý
bool cmp(int i, int j)
{
	return deg[i] < deg[j];
}
vector<pii> G;

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	vector<int> rank(n);
	vector<int> onelink;
	for (int i = 0; i < n; ++i)
		rank[i] = i;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		deg[a]++, deg[b]++;
	}
	sort(rank.begin(), rank.end(), cmp);


	int ed = n;
	for (int i = 0; i < ed; ++i) {
		int x = rank[i];
		if (deg[x] == 1) {
			onelink.push_back(x);
			cnt++;
		}
		else if (onelink.size() >= deg[x] - 1) {
			for (int j = 0; j < deg[x] - 1; ++j) {
				int y = onelink[onelink.size() - 1];
				G.push_back(pii(x, y));
				onelink.pop_back();
			}
			onelink.push_back(x);
			cnt++;
		}
		else if (onelink.size() + ed - i - 1 >= deg[x] - 1) {
			for (int j = 0; j < onelink.size(); ++j) {
				int y = onelink[j];
				G.push_back(pii(x, y));
			}
			for (int j = 0; j < deg[x] - 1 - onelink.size(); ++j) {
				G.push_back(pii(x, rank[--ed]));
			}
			onelink.clear();
			onelink.push_back(x);
			cnt++;
		}
		else {
			for (int j = 0; j < onelink.size(); ++j)
				G.push_back(pii(x, onelink[j]));
			for (int j = i + 1; j < ed; ++j)
				G.push_back(pii(x, rank[j]));
			onelink.clear();
			break;
		}
	}

	if (onelink.size() > 0) {
		if (onelink.size() != 2) cnt--;
		for (int i = 1; i < onelink.size(); ++i)
			G.push_back(pii(onelink[0], onelink[i]));
	}

	cout << n - cnt << endl;
	cout << n << " " << n - 1 << endl;
	for (int i = 0; i < G.size(); ++i)
		cout << G[i].first << " " << G[i].second << endl;
	return 0;
}