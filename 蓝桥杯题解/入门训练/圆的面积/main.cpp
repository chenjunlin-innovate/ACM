#include<iostream>

using namespace std;

#define Pi 3.14159265358979323

int main() {
	int x;
	cin >> x;
	double y;
	y = x * x * Pi;
	printf("%.7f", y);
	return 0;
}