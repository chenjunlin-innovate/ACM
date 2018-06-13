#include<iostream>
#include<vector>

using namespace std;

int ans[100050];
// vector<int> ans(100050,0);

void init() {
	for (int i(0); i < 100050; i++)ans[i] = 0;
	for (int i(1); i <= 100000; i++) {
		int sum(i);
		int num(i);
		while (num !=0){
			sum += num % 10;
			num /= 10;
		}
		if (ans[sum] == 0)ans[sum] = i;
	}
}

int main() {
	init();
	int T;
	cin >> T;
	while (T--){
		int x;
		cin >> x;
		cout << ans[x] << endl;
	}
	return 0;
}