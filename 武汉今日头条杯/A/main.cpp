#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#include<stdio.h>

using namespace std;

int main() {
	int x;

	cout << "1 2 3 4 5" << endl;
	cout << flush;
	int max1, max2;
	for (int i(0); i < 5; i++) {
		cin >> x;
		if (x == 1)
			max1 = i + 1;
		if (x == 2)
			max2 = i + 1;
	}

	cout << "6 7 8 9 10" << endl;
	cout << flush;
	int max3, max4;
	for (int i(0); i < 5; i++) {
		cin >> x;
		if (x == 1)
			max3 = i + 6;
		if (x == 2)
			max4 = i + 6;
	}

	
	cout << "11 12 13 14 15" << endl;
	cout << flush;
	int max5, max6;
	for (int i(0); i < 5; i++) {
		cin >> x;
		if (x == 1)
			max5 = i + 11;
		if (x == 2)
			max6 = i + 11;
	}

	
	cout << "16 17 18 19 20" << endl;
	cout << flush;
	int max7, max8;
	for (int i(0); i < 5; i++) {
		cin >> x;
		if (x == 1)
			max7 = i + 16;
		if (x == 2)
			max8 = i + 16;
	}


	cout << "21 22 23 24 25" << endl;
	cout << flush;
	int max9, max10;
	for (int i(0); i < 5; i++) {
		cin >> x;
		if (x == 1)
			max9 = i + 21;
		if (x == 2)
			max10 = i + 21;
	}
	cout << max1 << " " << max3 << " " << max5 << " " << max7 << " " << max9 << endl;
	cout << flush;
	vector<int>race(5);
	for (int i(0); i < 5; i++) {
		cin >> race[i];
	}
	if (race[0] == 1) {
		cout << max2 << " " << max3 << " " << max5 << " " << max7 << " " << max9 << endl;
		cout << flush;

		for (int i(0); i < 5; i++) {
			cin >> race[i];
		}
		cout << max1 << ' ';

		if (race[0] == 1) {
			cout << max2 << ' ';
		}else if (race[1] == 1) {
			cout << max3 << ' ';
		}
		else if (race[2] == 1) {
			cout << max5 << ' ';
		}
		else if (race[3] == 1) {
			cout << max7 << ' ';
		}
		else if (race[4] == 1) {
			cout << max9 << ' ';
		}
	}
	else if (race[1] == 1) {
		cout << max4 << " " << max1 << " " << max5 << " " << max7 << " " << max9 << endl;
		cout << flush;

		for (int i(0); i < 5; i++) {
			cin >> race[i];
		}
		cout << max3 << ' ';
		if (race[0] == 1) {
			cout << max4 << ' ';
		}
		else if (race[1] == 1) {
			cout << max1 << ' ';
		}
		else if (race[2] == 1) {
			cout << max5 << ' ';
		}
		else if (race[3] == 1) {
			cout << max7 << ' ';
		}
		else if (race[4] == 1) {
			cout << max9 << ' ';
		}
	}
	else if (race[2] == 1) {
		cout << max6 << " " << max3 << " " << max1 << " " << max7 << " " << max9 << endl;
		cout << flush;

		for (int i(0); i < 5; i++) {
			cin >> race[i];
		}

		cout << max5 << " ";
		if (race[0] == 1) {
			cout << max6 << ' ';
		}
		else if (race[1] == 1) {
			cout << max3 << ' ';
		}
		else if (race[2] == 1) {
			cout << max1 << ' ';
		}
		else if (race[3] == 1) {
			cout << max7 << ' ';
		}
		else if (race[4] == 1) {
			cout << max9 << ' ';
		}
	}
	else if (race[3] == 1) {
		cout << max8 << " " << max3 << " " << max5 << " " << max1 << " " << max9 << endl;
		cout << flush;

		for (int i(0); i < 5; i++) {
			cin >> race[i];
		}
		cout << max7 << ' ';
		if (race[0] == 1) {
			cout << max8 << ' ';
		}
		else if (race[1] == 1) {
			cout << max3 << ' ';
		}
		else if (race[2] == 1) {
			cout << max5 << ' ';
		}
		else if (race[3] == 1) {
			cout << max1 << ' ';
		}
		else if (race[4] == 1) {
			cout << max9 << ' ';
		}
	}
	else if (race[4] == 1) {
		cout << max10 << " " << max3 << " " << max5 << " " << max7 << " " << max1 << endl;
		cout << flush;

		for (int i(0); i < 5; i++) {
			cin >> race[i];
		}
		cout << max9 << " ";
		if (race[0] == 1) {
			cout << max10 << ' ';
		}
		else if (race[1] == 1) {
			cout << max3 << ' ';
		}
		else if (race[2] == 1) {
			cout << max5 << ' ';
		}
		else if (race[3] == 1) {
			cout << max7 << ' ';
		}
		else if (race[4] == 1) {
			cout << max1 << ' ';
		}
	}
	cout << "0 0 0" << endl;
	cout << flush;
}