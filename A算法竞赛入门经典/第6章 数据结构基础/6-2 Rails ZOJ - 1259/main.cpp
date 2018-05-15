#include <iostream>
#include <stack>

using namespace std;
const int len = 1024;
int coaches[len];

int main() {

	int n;
	while (cin >> n, n) {
		stack<int> s;
		while (cin >> coaches[0], coaches[0]) {

			for (int i = 1; i < n; i++) {
				cin >> coaches[i];
			}
			int lenB = 0, aId = 1;
			bool ok = true;
			while (lenB < n) {

				if (aId == coaches[lenB]) { aId++; lenB++; }
				else if (!s.empty() && s.top() == coaches[lenB]) { s.pop(); lenB++; }
				else if (aId <= n) s.push(aId++);
				else { ok = false; break; }

			}

			cout << (ok ? "Yes" : "No") << endl;
		}
		cout << endl;
	}

	return 0;
}