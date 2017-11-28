#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	int N, M;
	while (cin >> N >> M) {
		map<long long, int>all;
		string value;
		for (int i(0); i < N; i++) {
			cin >> value;
			long long sum(0);
			for (int j(0); j < value.size(); j++) {
				sum *= 10;
				long long  l=(value[j] - 'A') / 3 + 2;
				if (l <= 7)
					sum += l;
				else {
					l = (value[j] - 'Q') / 3 + 7;
					if (l <= 9)
						sum += l;
					else
						sum += 9;
				}
			}
			all[sum]++;
		}
		long long q;
		for (int i(0); i < M; i++) {
			cin >> q;
			cout << all[q]<<endl;
		}
	}
	return 0;
}