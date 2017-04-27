#pragma once
#include "Tutorial.h"

typedef Tutorial TElement;

class DynamicVector {
private:
	int size;
	int capacity;
	TElement* elems;

public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	DynamicVector& operator-(TElement & e);

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	// Adds an element to the current DynamicVector.
	void add(const TElement& e);
	void DynamicVector::remove(const Tutorial t);

	int DynamicVector::getPos(const double id) const;

	int getSize() const;
	TElement* getAllElems() const;
	TElement getElem(const double id) const;
private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};