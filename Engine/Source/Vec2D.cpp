#include "Vec2D.h"
#include <cmath>

Vec2D::Vec2D(float x, float y) :
	  x(x)
	, y(y)
{
}

Vec2D::Vec2D() :
	  x(0.0f)
	, y(0.0f)
{
}

float Vec2D::Magnitude() const
{
	return sqrtf(MagnitudeSq());
}

float Vec2D::MagnitudeSq() const
{
	return x * x + y * y;
}

float Vec2D::Distance(const Vec2D & rhs) const
{
	return sqrtf(DistanceSq(rhs));
}

float Vec2D::DistanceSq(const Vec2D & rhs) const
{
	return (x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y);
}

Vec2D Vec2D::operator+(const Vec2D & rhs) const
{
	return Vec2D(x + rhs.x, y + rhs.y);
}

Vec2D & Vec2D::operator+=(const Vec2D & rhs)
{
	return *this = *this + rhs;
}

Vec2D Vec2D::operator-(const Vec2D & rhs) const
{
	return Vec2D(x - rhs.x, y - rhs.y);
}

Vec2D & Vec2D::operator-=(const Vec2D & rhs)
{
	return *this = *this - rhs;
}

Vec2D Vec2D::operator*(const Vec2D & rhs) const
{
	return Vec2D(x * rhs.x, y * rhs.y);
}

Vec2D & Vec2D::operator*=(const Vec2D & rhs)
{
	return *this = *this * rhs;
}

Vec2D Vec2D::operator*(float rhs) const
{
	return Vec2D(x * rhs, y * rhs);
}

Vec2D & Vec2D::operator*=(float rhs)
{
	return *this = *this * rhs;
}

Vec2D Vec2D::operator/(const Vec2D & rhs) const
{
	return Vec2D(x / rhs.x, y / rhs.y);
}

Vec2D & Vec2D::operator/=(const Vec2D & rhs)
{
	return *this = *this / rhs;
}

bool Vec2D::operator==(const Vec2D & rhs) const
{
	return x == rhs.x && y == rhs.y;
}

bool Vec2D::operator!=(const Vec2D & rhs) const
{
	return !(*this == rhs);
}
