#include "Car.h"

void Car::Move()
{
	++pos;
}

void Car::operator++()
{
	++pos;
}

void Car::ToString()
{
	std::cout << "Car has position " << pos << "\n";
}

void Sedan::Move()
{
	if (turbo)
	{
		pos += 10;
	}
	else
	{
		Car::Move();
	}
}

void Vector2::Add(Vector2 v)
{
	x += v.x;
	y += v.y;
}

Vector2 Vector2::operator+(Vector2 v)
{
	Vector2 ret;
	ret.x += v.x;
	ret.y += v.y;

	return ret;
}