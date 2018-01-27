#include<iostream>

using namespace std;

class Vector3
{
public:
	Vector3(float fx, float fy, float fz)
		:x(fx), y(fy), z(fz)
	{
	}

	// Subtract
	Vector3 operator - (const Vector3& v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	// Dot product
	float Dot(const Vector3& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	// Cross product
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

int main() {
	Vector3 a(0, 0, 0), b(1, 0, 0), c(0, 1, 0), d(1, 0, 0);
	cout << PointinTriangle1(a, b, c, d) << endl;
}