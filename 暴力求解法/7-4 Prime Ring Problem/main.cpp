#include<iostream>
#include<vector>

using namespace std;

int n;
int A[100];
int vis[100];

bool isp(int a) {
	for (int i(2); i*i <= a; i++) {
		if (a%i == 0)
			return false;
	}
	return true;
}

void dfs(int cur) {
	if (cur == n && isp(A[n - 1] + A[0])) {
		for (int i(0); i < n-1; i++) {
			cout << A[i]<<" ";
		}
		cout <<A[n-1]<< endl;
	}
	else {
		for (int i = 1; i < n; i++) {
			if (!vis[i] && isp(i + 1 + A[cur-1])) {
				A[cur] = i + 1;
				vis[i] = 1;
				dfs(cur + 1);
				vis[i] = 0;
			}
		}
	}
}

int main() {
	int t(0);
	while (cin>>n)
	{
		if (t!=0)cout << endl;
		t++;
		for (int i(0); i < 100; i++) {
			vis[i] = 0;
		}
		A[0] = 1;
		vis[0] = 1;
		cout << "Case " << t << ":" << endl;
		dfs(1);
	}
}