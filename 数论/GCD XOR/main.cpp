#include<iostream>
#include<stdio.h>
using namespace std;

const int maxn = 30000000 + 5;
int ans[maxn];

void init() {
	for (int i(1); i < maxn/2; i++) {
		for (int j(i * 2); j < maxn; j+=i) {
			int b = j - i;
			if ((j^b) == i)ans[j]++;
		}
	}
	for (int i(1); i < maxn; i++) {
		ans[i] += ans[i - 1];
	}
}

int main() {
	int T;
	cin >> T;
	init();
	for(int i(0);i<T;i++){
		int n;
		cin >> n;
		printf("Case %d: %d\n", i + 1, ans[n]);
	}
	return 0;
}