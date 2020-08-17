#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D( const int& x_in, const int& y_in )
	:
	x(x_in),
	y(y_in)
{
}

Vector2D::Vector2D( const Vector2D& ref )
{
	x = ref.x;
	y = ref.y;
}

Vector2D::~Vector2D()
{
}

Vector2D Vector2D::operator+( const Vector2D& rhs )
{
	return Vector2D( x + rhs.x, y + rhs.y );
}

Vector2D Vector2D::operator-( const Vector2D& rhs )
{
	return Vector2D( x - rhs.x, y - rhs.y );
}

Vector2D Vector2D::operator*( float rhs )
{
	return Vector2D( x * rhs, y * rhs);
}

Vector2D& Vector2D::operator=( const Vector2D& rhs )
{
	if( this != &rhs )
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

	return sqrt( length );
}

Vector2D& Vector2D::GetNormal()
{
	const float len = GetLength();
	if( len != 0.0f )
	{
		return *this * (1.0f / len);
	}
	return *this;
}
