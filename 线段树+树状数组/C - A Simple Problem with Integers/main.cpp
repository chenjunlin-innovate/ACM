#include<iostream>
#include<vector>
#include<string>

#pragma warning(disable:4996)

using namespace std;

int a[60000];
int b[500000];
int c[500000];

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

void Updata(int left, int right, int L,int R, int C, int rt) {
	if (left == right) {
		b[rt] += C;
		return;
	}
	int m = (left + right) >> 1;
	if (L <= m)Updata(left, m, L, R, C, rt << 1);
	if (R > m) Updata(m + 1, right, L, R, C, rt << 1 | 1);

	b[rt] = b[rt << 1] + b[rt << 1 | 1];
}

long int Query(int left, int right, int L, int R, int rt) {
	if (L <= left&&right <= R)
		return b[rt];

	int m = (left + right) >> 1;
	long int ans(0);
	if (L <= m)ans += Query(left, m, L, R, rt << 1);
	if (R > m)ans += Query(m + 1, right, L, R, rt << 1 | 1);

	return ans;
}

int main() {
	int n, x;
	while(scanf("%d%d", &x,&n) != EOF) {

		Build(1, x, 1);

		//cout << "Case " << i << ':' << endl;

		char l;
		for (int i(0); i < n; i++) {
			scanf("\n%c", &l);
			if (l == 'E')break;
			else if (l == 'Q') {
				int m, n;
				scanf("%d%d", &m, &n);
				cout << Query(1, x, m, n, 1) << endl;
			}
			else if (l == 'C') {
				int m, n, l;
				scanf("%d%d%d", &m, &n, &l);
				Updata(1, x, m, n, l, 1);
			}
		}
	}
	return 0;
}