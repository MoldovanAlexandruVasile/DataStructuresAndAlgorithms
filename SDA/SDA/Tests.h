#pragma once
#include "MultiMap.h"
#include <assert.h>


void tests()
{
	MultiMap mm{15};
	assert(mm.add(1, "Laura Ina") == 0);			//Add a new guests
	assert(mm.add(2, "Gigel") == 0);				//Add another
	assert(mm.search(1, "Laura Ina") != -1);		//Search the guest. And it find it
	assert(mm.remove(1, "Laura Ina") == 0);		//Removes the guest
	assert(mm.search(1, "Laura Ina") == -1);		//Can't find the guest
	assert(mm.remove(1, "Laura Ina") == -1);		//Can't delete an inexistent guest
}