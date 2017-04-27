#include "DynamicVector.h"
#include <string.h>

DynamicVector::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;
}

DynamicVector& DynamicVector::operator-(TElement& e) {
	int pos = getPos(e.getId());
	for (int i = pos; i < this->size; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;

	return *this;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
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

void DynamicVector::add(const TElement& e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

void DynamicVector::remove(const Tutorial t) {
	TElement e = getElem(t.getId());
	int pos = getPos(t.getId());
	for (int i = pos; i < this->size; i++)
		this->elems[i] = this->elems[i+1];
	this->size--;
}

void DynamicVector::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

TElement* DynamicVector::getAllElems() const
{
	return this->elems;
}

int DynamicVector::getSize() const
{
	return this->size;
}

int DynamicVector::getPos(const double id) const {
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].getId() == id) {
			return i;
			break;
		}
	return -1;
}

TElement DynamicVector::getElem(const double id) const {
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].getId() == id) {
			return this->elems[i];
			break;
		}
	return Tutorial();
}

