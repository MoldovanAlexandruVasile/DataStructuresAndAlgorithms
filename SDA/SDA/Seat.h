#pragma once
#include <string>

class Seat
{
private:
	int key; //ID of the table
	std::string name; //The name of the guest

public:
	Seat(int key, std::string name); //Guest constructor

	Seat(); //default constructor

	Seat(const Seat& other); //Copy constructor

	~Seat(); //destructor

	bool operator == (int other); //override of the operator ==. Compare 2 integers
	bool operator == (Seat other); //override of the operator ==. Compare two variables of type Seat

	int getKey() { return key; }		//Return the key of the current element
	std::string getName() { return name; }	//Return the name of the current element

	void setKey(int key) { this->key = key; }	//Sets the key of a TElement
	void setName(std::string name) { this->name = name; }	//Sets the name of a TElement
};