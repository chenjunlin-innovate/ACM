#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

class Node {
public:
	long long num;
	Node *l;
	Node *r;
	Node() :l(NULL), r(NULL), num(-1) {}
};

int main() {
	int n;
	while (cin >> n) {
		vector<long long>a(n);
		vector<long long>b(n);
		Node *MainNode = new Node();
		for (int i(0); i < n; i++) {
			cin >> a[i];
		}
		for (int i(0); i < n; i++) {
			cin >> b[i];
		}
		for (int i(0); i < n; i++) {
			long long p = b[i];
			Node *thisNode = MainNode;
			for (int i(30); i >= 0; i--) {
				if (p & (1 << i)) {
					if (thisNode->r != NULL) {
						thisNode = thisNode->r;
					}
					else
					{
						thisNode->r = new Node();
						thisNode = thisNode->r;
					}
				}
				else {
					if (thisNode->l != NULL) {
						thisNode = thisNode->l;
					}
					else
					{
						thisNode->l = new Node();
						thisNode = thisNode->l;
					}
				}
			}
			thisNode->num = p;
		}
		for (int i(0); i < n; i++) {
			long long p = a[i];
			Node *thisNode = MainNode;
			Node *fatherNode = MainNode;
			bool x(1);
			for (int j(30); j >= 0; j--) {
				if (thisNode->r != NULL && thisNode->l != NULL) {
					fatherNode = thisNode;
					if (p&(1 << j)) {
						if (thisNode->r != NULL) {
							thisNode = thisNode->r;
							x = 1;
						}
						else {
							thisNode = thisNode->l;
							x = 0;
						}
					}
					else
					{
						if (thisNode->l != NULL) {
							thisNode = thisNode->l;
							x = 0;
						}
						else {
							thisNode = thisNode->r;
							x = 1;
						}
					}
				}
				else {
					if (p&(1 << j)) {
						if (thisNode->r != NULL)
							thisNode = thisNode->r;
						else
							thisNode = thisNode->l;
					}
					else
					{
						if (thisNode->l != NULL)
							thisNode = thisNode->l;
						else
							thisNode = thisNode->r;
					}
				}
			}
			if (x == 0)fatherNode->l = NULL;
			else fatherNode->r = NULL;
			int output = thisNode->num ^ p;
			cout << output << ' ';
		}
		cout << endl;
	}
	return 0;
}