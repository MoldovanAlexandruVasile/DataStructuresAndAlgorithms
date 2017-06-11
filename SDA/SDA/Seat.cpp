#include "Seat.h"

Seat::Seat(int key, std::string name)
{
	this->key = key;
	this->name = name;
}

Seat::Seat()
{
	key = -1;
	name = "";
}

Seat::Seat(const Seat& other)
{
	key = other.key;
	name = other.name;
}

Seat::~Seat()
{
}

bool Seat::operator==(int other)
{
	return key == other;
}

bool Seat::operator==(Seat other)
{
	return key == other.key && name == other.name;
}
