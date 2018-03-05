#pragma once

class Vec2D
{
public:
	Vec2D(float x, float y);
	Vec2D();
	float Magnitude() const;
	float MagnitudeSq() const;
	float Distance(const Vec2D& rhs) const;
	float DistanceSq(const Vec2D& rhs) const;

	//operators
	Vec2D operator+(const Vec2D& rhs) const;
	Vec2D& operator+=(const Vec2D& rhs);
	Vec2D operator-(const Vec2D& rhs) const;
	Vec2D& operator-=(const Vec2D& rhs);
	Vec2D operator*(const Vec2D& rhs) const;
	Vec2D& operator*=(const Vec2D& rhs);
	Vec2D operator*(float rhs) const;
	Vec2D& operator*=(float rhs);
	Vec2D operator/(const Vec2D& rhs) const;
	Vec2D& operator/=(const Vec2D& rhs);
	bool operator==(const Vec2D& rhs) const;
	bool operator!=(const Vec2D& rhs) const;

	float x, y;
};