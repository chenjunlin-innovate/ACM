#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>

using namespace std;

long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }

int main() {
	int n;
	cin >> n;
	long long a, b, c;
	for (int i(0); i < n; i++) {
		scanf("%I64d%I64d%I64d", &a, &b, &c);

		a -= (a / b * b);		
		if (a == 0) {
			printf("Finite\n");
			continue;
		}
		b /= gcd(a, b);
		if (b == 1) {
			printf("Finite\n");
			continue;
		}
		long long y = gcd(b, c);
		if (y == 1) {
			printf("Infinite\n");
			continue;
		}
		while (y != 1) {
			while (b%y==0)
			{
				b /= y;
			}
			y = gcd(b, c);
			
		}
		if (b == 1)printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}
