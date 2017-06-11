#include "MultiMap.h"

int MultiMap::HashFunction(int k, int i)
{
	return ((k % m) + i) % m;
}

MultiMap::~MultiMap()
{
}

int MultiMap::add(int key, std::string name)
{
	int i = 0;
	int pos = HashFunction(key, i);
	while (i < this->m && !(dv[pos] == -1))
	{
		i++;
		pos = HashFunction(key, i);
	}
	if (i == m)
		resize();

	dv[pos] = Seat(key, name);

	return 0;
}

int MultiMap::remove(int key, std::string name)
{
	int pos = this->search(key, name);
	if (pos != -1)
	{
		dv[pos].setKey(-2);
		return 0;
	}
	return -1;
}

int MultiMap::search(int key, std::string name)
{
	Seat s(key, name);
	int i = 0;
	int pos = HashFunction(key, i);
	while (i < this->m && !(dv[pos] == s) && !(dv[pos] == -1) && !(dv[pos] == -2))
	{
		i++;
		pos = HashFunction(key, i);
	}

	if (i == m)
		return -1;

	if (dv[pos] == s)
		return pos;
	return -1;
}


void MultiMap::resize()
{
	DynamicVector<Seat> v{ int(m * 1.5) };
	Iterator it{*this};
	m = int(m * 1.5);
	while(it.valid())
	{
		Seat s = it.getCurrent();
		int i = 0;
		int pos = HashFunction(s.getKey(), i);
		while (i < this->m && !(v[pos] == -1))
		{
			i++;
			pos = HashFunction(s.getKey(), i);
		}
		v[pos] = s;
		it.next();
	}

	dv = v;
}


MultiMap::Iterator::Iterator(MultiMap& mm):mm(mm)
{
	int i = 0;
	while (i < mm.m && (mm.dv[i] == -1 || mm.dv[i] == -2))
		i++;
	pos = i;
}

MultiMap::Iterator::~Iterator()
{
}

Seat MultiMap::Iterator::getCurrent()
{
	return mm.dv[pos];
}

bool MultiMap::Iterator::valid()
{
	return pos < mm.m && pos >= 0;
}

void MultiMap::Iterator::next()
{
	int i = pos + 1;
	while (i < mm.m && (mm.dv[i] == -1 || mm.dv[i] == -2))
		i++;
	pos = i;
}
