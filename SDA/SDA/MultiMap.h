#pragma once
#include "DynamicVector.h"
#include "Seat.h"

class MultiMap
{
public:
	DynamicVector<Seat> dv; //Vector of guests
	int m; //Number of seats

private:
	/*
	Returns the insertion position
	INPUT:  k - key
     	    i - probe number 
	OUTPUT: int - The position coresponding to k and i
	*/
	int HashFunction(int k, int i);


public:
	/*
	Returns an empty multimap
	INPUT:  m - dimension
	OUTPUT: MultiMap - the multimap created.
	*/
	MultiMap(int m) : m(m), dv{m} {};

	MultiMap() = default; //Default constructor 
	~MultiMap(); //destructor

	/*
	Adds a new guest to a table
	INPUT:  k - Table number
     	    name - Guest name 
	OUTPUT: 0 - Added succeded
	*/
	int add(int key, std::string name);

	/*
	Removes a guest from a table
	INPUT:  k - Table number
			name - Guest name
	OUTPUT: 0 - Removed succeded
			-1 - Remove failed
	*/
	int remove(int key, std::string name);

	/*
	Search for a guests in the restaurant
	INPUT:  k - Table number
			name - Guest name
	OUTPUT: pos - Search succeded
			-1 - Search failed
	*/
	int search(int key, std::string name);

	//Resizes the MultiMap when it is full
	void resize();


	class Iterator
	{
	private:
		int pos; //Current Position
		MultiMap& mm; //Iterator over MultiMap

	public:
		Iterator(MultiMap& mm); //Iterator constructor
		Iterator() = default;   //Default constructor of the iterator
		~Iterator();				//Destructor of the iterator
		Seat getCurrent();		//gives the current element from the position
		bool valid();			//Tests if the current position is a valid one
		void next();				//Go to the next position
	};
};
