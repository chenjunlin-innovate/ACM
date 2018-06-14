#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		string a;
		cin >> a;
		a += a;
		int ans(0);
		for(int i(0);i<a.size()/2;i++){
			for (int j(i), l(ans), t(0); t < a.size()/2; t++, j++, l++) {
				if (a[j] < a[l])ans = i;
				else if (a[j] > a[l])break;
			}
		}
		//多条件for循环， t代表判断长度，ans代表最小字典序的起点，j为当前遍历的起点。
		for (int i(ans), t(0); t < a.size() / 2; t++, i++) {
			cout << a[i];
		}
		cout << endl;
	}
}