#include<iostream>

using namespace std;

int N;
int dir[5001] = { 0 };
int f[50001] = { 0 };

int calc(int k) {
	memset(f, 0, sizeof(f));
	int res = 0;
	int sum = 0;
	for (int i(0); i + k <= N; i++) {
		if ((dir[i] + sum) % 2 != 0) {
			res++;
			f[i] = 1;
		}
		sum += f[i];
		if (i - k + 1 >= 0) {
			sum -= f[i - k + 1];
		}
	}
	for (int i(N - k + 1); i < N; i++) {
		if ((dir[i] + sum) % 2 != 0) {
			return -1;
		}
		if (i - k + 1 >= 0) {
			sum -= f[i - k + 1];
		}
	}

	return res;
}

int main() {
	while (cin >> N) {
		char x;
		for (int i(0); i < N; i++) {
			cin >> x;
			if (x == 'B')
				dir[i] = 1;
		}
		int K = 1;
		int M = N;
		for (int i(1); i <= N; i++) {
			int m = calc(i);
			if (m >= 0 && M > m) {
				K = i;
				M = m;
			}
		}
		cout << K << ' ' << M << endl;
	}
}


