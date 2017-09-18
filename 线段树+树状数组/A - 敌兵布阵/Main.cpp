#include<iostream>
#include<vector>
#include<string>

#pragma warning(disable:4996)

using namespace std;

int a[60000];
int b[300000];

void Build(int p, int q, int rt) {
	if (p == q) {
		scanf("%d", &b[rt]);
		return;
	}
	int m = (p + q) >> 1;
	Build(p, m, rt << 1);
	Build(m + 1, q, rt << 1 | 1);

	b[rt] = b[rt << 1] + b[rt << 1 | 1];
}

void Updata(int left,int right,int L,int C,int rt) {
	if (left == right) {
		b[rt] += C;
		return;
	}
	int m = (left + right) >> 1;
	if (L <= m)Updata(left, m, L, C, rt << 1);
	else Updata(m + 1, right, L, C, rt << 1 | 1);

	b[rt] = b[rt << 1] + b[rt << 1 | 1];
}

int Query(int left,int right,int L,int R,int rt) {
	if (L <= left&&right <= R)
		return b[rt];

	int m = (left + right) >> 1;
	int ans(0);
	if (L <= m)ans += Query(left, m, L, R, rt << 1);
	if (R > m)ans += Query(m + 1, right, L, R, rt << 1 | 1);

	return ans;
}

int main(){
	int n;	cin >> n;
	for (int i(1); i <= n; i++) {
		int x;	cin >> x;

		Build(1, x, 1);

		cout << "Case " << i << ':' << endl;

		char l[20];
		while (scanf("%s", l)!=EOF) {
			if (l[0] == 'E')break;
			else if (l[0] == 'Q') {
				int m, n;
				scanf("%d%d", &m, &n);
				cout << Query(1, x, m, n, 1) << endl;
			}
			else if (l[0] == 'S') {
				int m, n;
				scanf("%d%d", &m, &n);
				Updata(1, x, m, -n, 1);
			}
			else if (l[0] == 'A') {
				int m, n;
				scanf("%d%d", &m, &n);
				Updata(1, x, m, n, 1);
			}
		}
	}
	return 0;
}