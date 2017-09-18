#include<iostream>
#include<string>

#pragma warning(disable:4996);

using namespace std;

int b[800004];

void Build(int p, int q, int rt) {
	if (p == q) {
		scanf("%d", &b[rt]);
		return;
	}
	int m = (p + q) >> 1;
	Build(p, m, rt << 1);
	Build(m + 1, q, rt << 1 | 1);

	b[rt] = (b[rt << 1] >= b[rt << 1 | 1]) ? b[rt << 1] : b[rt << 1 | 1];
}

void Updata(int left, int right, int L, int C, int rt) {
	if (left == right) {
		b[rt] = C;
		return;
	}
	int m = (left + right) >> 1;
	if (L <= m)Updata(left, m, L, C, rt << 1);                
	else Updata(m + 1, right, L, C, rt << 1 | 1);

	if (b[rt] < C)
		b[rt] = C;
}

int Query(int left, int right, int L, int R, int rt) {
	if (L <= left&&right <= R)
		return b[rt];

	int m = (left + right) >> 1;

	if (L <= m)return Query(left, m, L, R, rt << 1);
	if (R > m)return Query(m + 1, right, L, R, rt << 1 | 1);
}

int main() {
	int x, y;
	int m, n;
	while(scanf("%d%d",&x,&y)) {
		Build(1, x, 1);
		char l;
		for (int i(0); i < y;i++) {
			scanf("\n%c", &l);
			if (l == 'Q') {
				scanf("%d%d", &m, &n);
				printf("%d\n", Query(1, x, m, n, 1));
			}
			else if (l == 'U') {
				scanf("%d%d", &m, &n);
				Updata(1, x, m, n, 1);
			}
		}
	}
	return 0;
}