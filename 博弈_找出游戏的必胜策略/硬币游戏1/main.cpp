#include <iostream>  
using namespace std;
const int MAX_K = 105;
const int MAX_X = 10005;
int X, K, a[MAX_K];
bool win[MAX_X];
void solve()
{
	win[0] = false;
	for (int j = 1; j <= X; j++) {
		win[j] = false;
		for (int i = 0; i<K; i++) {
			//win[j] |= a[i] <= j && !win[j - a[i]];
			if (j - a[i] == 0)win[j] = 1;
			else if (a[i] < j)
				if (!win[j - a[i]])win[j] = 1;
		}
	}
	if (win[X]) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}
int main()
{
	while (cin >> X >> K) {
		for (int i = 0; i<K; i++)
			cin >> a[i];
		solve();
	}
	return 0;
}
