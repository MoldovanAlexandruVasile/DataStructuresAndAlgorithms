#pragma once

template<class TElement>
class DynamicVector
{
private:
	TElement* elems;
	int size;
	int capacity;

public:

	//Constructor
	DynamicVector(int capacity = 10);

	//Creates a copy of the Array
	DynamicVector(const DynamicVector& v);

	//Destructor
	~DynamicVector();

	//Returns the size of the dynamic vector.
	int getSize() const;

	//Create the operator "="
	DynamicVector& operator=(DynamicVector v)
	{
		if (this == &v)
			return *this;
		this->size = v.size;
		this->capacity = v.capacity;
		delete[] this->elems;
		this->elems = new TElement[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->elems[i] = v.elems[i];
		return *this;
	}

	TElement& operator[](int pos);

private:
	//Resizes the vector.
	void resize(double factor = 1.5);
};


template<class TElement>
DynamicVector<TElement>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}


template<class TElement>
DynamicVector<TElement>::DynamicVector(const DynamicVector<TElement>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template<class TElement>
DynamicVector<TElement>::~DynamicVector()
{
	delete[] this->elems;
}

template<class TElement>
inline TElement & DynamicVector<TElement>::operator[](int pos)
{
	size = capacity;
	if (pos >= this->capacity)
		return TElement();
	return this->elems[pos];
}

template<class TElement>
void DynamicVector<TElement>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);
	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];
	delete[] this->elems;
	this->elems = els;

}

template<class TElement>
int DynamicVector<TElement>::getSize() const
{
	return this->size;
}