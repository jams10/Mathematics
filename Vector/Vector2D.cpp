#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(const int& x_in, const int& y_in)
	:
	x(x_in),
	y(y_in)
{
}

Vector2D::Vector2D(const Vector2D& ref)
{
	x = ref.x;
	y = ref.y;
}

Vector2D::~Vector2D()
{
}

Vector2D Vector2D::operator+(const Vector2D& rhs)
{
	return Vector2D(x + rhs.x, y + rhs.y);
}

Vector2D Vector2D::operator-(const Vector2D& rhs)
{
	return Vector2D(x - rhs.x, y - rhs.y);
}

Vector2D Vector2D::operator*(float rhs)
{
	return Vector2D(x * rhs, y * rhs);
}

Vector2D& Vector2D::operator=(const Vector2D& rhs)
{
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}

	return *this;
}


float Vector2D::GetLength()
{
	float length = 0.0f;
	length = x * x + y * y;

	return sqrt(length);
}

Vector2D Vector2D::GetNormal()
{
	const float len = GetLength();
	if (len != 0.0f)
	{
		return *this * (1.0f / len);
	}
	return *this;
}

/*
<비 const에 대한 C ++ 초기 값은 lvalue 여야합니다.>

https://www.it-swarm.dev/ko/c%2B%2B/%EB%B9%84-const%EC%97%90-%EB%8C%80%ED%95%9C-c-%EC%B4%88%EA%B8%B0-%EA%B0%92%EC%9D%80-lvalue-%EC%97%AC%EC%95%BC%ED%95%A9%EB%8B%88%EB%8B%A4/1040965278/

https://thrillfighter.tistory.com/351
*/
