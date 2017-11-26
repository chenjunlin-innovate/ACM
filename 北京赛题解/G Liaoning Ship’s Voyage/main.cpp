#include<algorithm>
#include<iostream>
#include<vector>
//写了一个错误的bfs，，然后超时了
using namespace std;

struct Point {
	double x, y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
};

double mult(Point a, Point b, Point c)
{
	return (a.x - c.x)*(b.y - c.y) - (b.x - c.x)*(a.y - c.y);
}

//aa, bb为一条线段两端点 cc, dd为另一条线段的两端点 相交返回true, 不相交返回false  
bool intersect(Point aa, Point bb, Point cc, Point dd)
{
	if (max(aa.x, bb.x)<min(cc.x, dd.x))
	{
		return false;
	}
	if (max(aa.y, bb.y)<min(cc.y, dd.y))
	{
		return false;
	}
	if (max(cc.x, dd.x)<min(aa.x, bb.x))
	{
		return false;
	}
	if (max(cc.y, dd.y)<min(aa.y, bb.y))
	{
		return false;
	}
	if (mult(cc, bb, aa)*mult(bb, dd, aa)<0)
	{
		return false;
	}
	if (mult(aa, dd, cc)*mult(dd, bb, cc)<0)
	{
		return false;
	}
	return true;
}


class Vector3
{
public:
	Vector3(float fx, float fy, float fz)
		:x(fx), y(fy), z(fz)
	{
	}

	Vector3 operator - (const Vector3& v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	bool operator == (const Vector3& v) const
	{
		return x == v.x&& y == v.y&& z == v.z;
	}

	float Dot(const Vector3& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	Vector3 Cross(const Vector3& v) const
	{
		return Vector3(
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);
	}

public:
	float x, y, z;
};

bool SameSide(Vector3 A, Vector3 B, Vector3 C, Vector3 P)
{
	Vector3 AB = B - A;
	Vector3 AC = C - A;
	Vector3 AP = P - A;

	Vector3 v1 = AB.Cross(AC);
	Vector3 v2 = AB.Cross(AP);

	return v1.Dot(v2) >= 0;
}

bool PointinTriangle1(Vector3 A, Vector3 B, Vector3 C, Vector3 P)
{
	return SameSide(A, B, C, P) &&
		SameSide(B, C, A, P) &&
		SameSide(C, A, B, P);
}

int q[]{ 0,1,0,-1,1,0,1,-1,1,1,1,-1,-1,1,-1,-1 };

Point p1, p2, p3;

bool bfs(int k,vector<vector<bool>> map,int x,int y) {
	map[x][y] = 0;
	if (x == map.size() - 1, y == map.size() - 1)return 1;
	if (k <= 1)return 0;
	bool kkk = 0;
	for (int i(0); i < 16; i += 2) {
		int Nx = x + q[i];
		int Ny = y + q[i + 1];

		if (Nx < map.size() && Ny < map.size() && Nx >= 0 && Ny >= 0) {
			if (map[Nx][Ny] == 1 && !(intersect(p1, p2, Point(x, y), Point(Nx, Ny)) || intersect(p1, p2, Point(x, y), Point(Nx, Ny)) || intersect(p1, p2, Point(x, y), Point(Nx, Ny))))
				kkk |= bfs(k - 1, map, Nx, Ny);
		}
	}
	return kkk;
}

int main() {
	int n;
	while (cin >> n) {
		char q;
		vector<vector<bool>> map(n, vector<bool>(n,0));
		double x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		p1.x = y1;p2.x = y2; p3.x = y3;
		p1.y = x1;p2.y = x2; p3.y = x3;
		Vector3 A(y1, x1, 0), B(y2, x2, 0), C(y3, x3, 0);
		for (int i(n - 1); i >= 0; i--) 
			for (int j(0); j < n; j++) {
				cin >> q;
				if (q == '.')
					if (!PointinTriangle1(A, B, C, Vector3(n - i - 1, j, 0)) || A == Vector3(n - i - 1, j, 0) || B == Vector3(n - i - 1, j, 0) || C == Vector3(n - i - 1, j, 0))
						map[i][j] = 1;
			}
		for (int i(n - 1); i >= 0; i--) {
			for (int j(0); j < n; j++)
				cout << map[i][j];
			cout<<endl;
		}
		bool o = 0;
		int max = n*n / 2;
		for (int i(0); i < max; i++) {
			if (bfs(i, map, 0, 0)) {
				o = 1;
				cout << i << endl;
				break;
			}
		}
		if (!o)cout << -1 << endl;

	}
}