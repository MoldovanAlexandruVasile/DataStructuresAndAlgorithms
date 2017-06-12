#pragma once
#include "MultiMap.h"
#include "DynamicVector.h"
#include "Seat.h"
#include <assert.h>


void tests()
{
	DynamicVector<Seat> v;
	DynamicVector<Seat> v1;
	v = v1;
	
	assert(v.getSize() == 0);
	assert(v[15].getKey() == -1);				
	assert(v[0].getName() == "");
	MultiMap mm{3};
	assert(mm.search(1, "Laura Ina") == -1);		//Search for a guest that does not exist
	assert(mm.add(1, "Laura Ina") == 0);			//Add a new guests
	assert(mm.add(1, "Mariana") == 0);			//Add another guest at table 1
	assert(mm.add(2, "Gigel") == 0);				//Add another guest
	assert(mm.add(3, "Ana") == 0);				//Add another guest
	assert(mm.search(1, "Laura Ina") != -1);		//Search the guest. And it find it
	assert(mm.search(1, "Mariana") != -1);		//Search the guest, he will be found
	assert(mm.remove(1, "Laura Ina") == 0);		//Removes the guest
	assert(mm.search(1, "Laura Ina") == -1);		//Can't find the guest
	assert(mm.remove(1, "Laura Ina") == -1);		//Can't delete an inexistent guest
	assert(mm.add(4, "Gigel") == 0);
	MultiMap mm2{ 2 };
	mm2 = mm;
	mm.resize();
}