#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool>visit;
vector<long long> all;
vector<vector<long long>>m_all;

long long dfs(int x) {
	long long m_min(all[x]);
	visit[x] = 1;
	for (int i(0); i < m_all[x].size(); i++) {
		if (!visit[m_all[x][i]])
			m_min = min(m_min, dfs(m_all[x][i]));
	}
	return m_min;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		
		all.clear();
		all.resize(n);
		m_all.clear();
		m_all.resize(n);
		visit.clear();
		visit.resize(n, false);
		for (int i(0); i < n; i++)
			cin >> all[i];

		vector<bool> it(n, 1);
		int x, y;
		for (int i(0); i < m; i++) {
			cin >> x >> y;
			m_all[x - 1].push_back(y - 1);
			m_all[y - 1].push_back(x - 1);
		}

		long long sum(0);
		for (int i(0); i < n; i++) {
			if (!visit[i])sum += dfs(i);
		}

		cout << sum << endl;
	}
}