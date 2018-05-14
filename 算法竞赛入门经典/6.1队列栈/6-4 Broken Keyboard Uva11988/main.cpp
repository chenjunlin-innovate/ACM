#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	string a;
	while (cin>>a)
	{
		int last(0);
		int cur(0);
		int next[100005];
		next[0] = -1;
		for (int i(1); i <= a.size(); i++) {
			if (a[i-1] == '[') {
				cur = 0;
			}
			else if (a[i-1] == ']') {
				cur = last;
			}
			else {
				next[i] = next[cur];
				next[cur] = i;
				if (cur == last)last = i;
				cur = i;
			}
		}
		for (int i = next[0]; i != -1; i = next[i]) {
			printf("%c",a[i-1]);
		}
		cout << endl;
	}
	return 0;
}