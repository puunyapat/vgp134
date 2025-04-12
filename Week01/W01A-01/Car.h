#pragma once
#include <iostream>
class Car
{
	public:
		virtual void Move(); // can slow down if use it too much.
		void ToString();
		void operator++();

	protected:
		bool turbo = true;
		int pos = 0;
		int fuel = 0;
};

class Sedan : public Car
{
	public:
		void Move() override;
};

class Vector2
{
	public:
		void Add(Vector2 v);
		Vector2 operator+(Vector2 v);

	private:
		int x;
		int y;
};