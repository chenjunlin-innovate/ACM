#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 50050
int a[N], first[N], q[N], vis[N], pre[N], fa[N], dep[N], sz[N], top[N], s[N], w[N], ms[N];
int n, m, Q, cnt, head, tail, now, tot;
struct node { int l, r, s; }T[N << 3];
struct edge { int y, next; }e[N << 1];
void addedge(int x, int y) {
	e[++cnt].next = first[x]; e[cnt].y = y; first[x] = cnt;
}
char ch, ctrl[3];
void read(int &x) {
	while (ch = getchar(), ch < '0' || ch > '9');
	x = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
}
void bfs() {
	head = tail = 0;
	q[++tail] = 1;
	vis[1] = 1;
	int x, y;
	while (head < tail) {
		x = q[++head];
		for (int i = first[x]; i; i = e[i].next) {
			y = e[i].y;
			if (y != fa[x] && !vis[y])
				fa[y] = x, dep[y] = dep[x] + 1, vis[y] = 1, q[++tail] = y;
		}
	}
	for (int j = tail; j; j--) {
		x = q[j];
		sz[x] ++;
		for (int i = first[x]; i; i = e[i].next) {
			y = e[i].y;
			if (y != fa[x]) {
				sz[x] += sz[y];
				if (sz[y] > sz[ms[x]]) ms[x] = y;
			}
		}
	}
}
void dfs() {
	s[tot = now = 1] = 1;
	top[1] = 1;
	int x, y;
	while (now) {
		x = s[now];
		w[x] = now;
		if (vis[x] == 1) {
			vis[x] = 2;
			if (ms[x]) {
				s[++tot] = ms[x];
				top[ms[x]] = top[x];
				pre[tot] = now;
				now = tot;
				continue;
			}
		}
		int flag = 0;
		for (int i = first[x]; i; i = e[i].next) {
			y = e[i].y;
			first[x] = i;
			if (vis[y] == 1 && y != fa[x] && y != ms[x]) {
				s[++tot] = y;
				top[y] = y;
				pre[tot] = now;
				flag = 1;
				break;
			}
		}
		if (flag) { now = tot; continue; }
		now = pre[now];
	}
}
void push_down(int k) {
	T[k * 2].s += T[k].s;
	T[k * 2 + 1].s += T[k].s;
	T[k].s = 0;
}
void add(int l, int r, int z, int k) {
	if (l == T[k].l && r == T[k].r) {
		T[k].s += z;
		return;
	}
	push_down(k);
	int m = T[k].l + T[k].r >> 1;
	if (m >= r)    add(l, r, z, k * 2);
	else if (m < l) add(l, r, z, k * 2 + 1);
	else {
		add(l, m, z, k * 2);
		add(m + 1, r, z, k * 2 + 1);
	}
}
void work(int x, int y, int z) {
	int t;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) t = x, x = y, y = t;
		add(w[top[x]], w[x], z, 1);
		x = fa[top[x]];
	}
	if (dep[x] < dep[y]) t = x, x = y, y = t;
	add(w[y], w[x], z, 1);
}
void build(int k, int l, int r) {
	T[k].l = l; T[k].r = r; T[k].s = 0;
	if (l == r) return;
	int m = l + r >> 1;
	build(k * 2, l, m);
	build(k * 2 + 1, m + 1, r);
}
int query(int x, int k) {
	if (x == T[k].l && x == T[k].r) return T[k].s;
	push_down(k);
	int m = T[k].l + T[k].r >> 1;
	if (m >= x) return query(x, k * 2);
	else return query(x, k * 2 + 1);
}
void clear() {
	memset(first, 0, sizeof first);
	memset(sz, 0, sizeof sz);
	memset(vis, 0, sizeof vis);
	memset(ms, 0, sizeof ms);
	cnt = 0;
}
int main() {
	while (scanf("%d%d%d", &n, &m, &Q) != EOF) {
		clear();
		int x, y, z;
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 1; i < n; i++) read(x), read(y), addedge(x, y), addedge(y, x);
		bfs(); dfs();
		build(1, 1, n);
		while (Q--) {
			scanf("%s", ctrl);
			if (ctrl[0] == 'I') {
				read(x); read(y); read(z);
				work(x, y, z);
			}
			else if (ctrl[0] == 'D') {
				read(x); read(y); read(z);
				work(x, y, -z);
			}
			else {
				read(x);
				if (x == 0) printf("0\n");
				else printf("%d\n", a[x] + query(w[x], 1));
			}
		}
	}
	return 0;
}