#pragma once

class Vector2D
{
public:
	Vector2D() = default;
	Vector2D( const int& x_in, const int& y_in );
	Vector2D( const Vector2D& ref );
	~Vector2D();
	Vector2D operator+( const Vector2D& rhs );
	Vector2D operator-( const Vector2D& rhs );
	Vector2D operator*( float rhs );
	Vector2D& operator=( const Vector2D& rhs );
	float GetLength();
	Vector2D& GetNormal();
private:
	float x;
	float y;
};