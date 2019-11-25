#include <iostream>
#include <cassert>

#include "vector.h"

Vector* createVector()
{
	Vector* v = new Vector();

	v->data = nullptr;
	v->size = 0;
	v->capacity = 0;

	return v;
}

void deleteVector(Vector* v)
{
	delete[] v->data;
	delete v;
}

Vector* copyVector(Vector* v)
{
	Vector* newVector = new Vector();
	newVector->size = v->size;
	newVector->capacity = v->capacity;

	newVector->data = new int[newVector->capacity];
	memcpy(newVector->data, v->data, v->size * sizeof(int));

	return newVector;
}

void swapVector(Vector* lh, Vector* rh)
{
	Vector* h = copyVector(lh);
	lh->data = rh->data;
	lh->size = rh->size;
	lh->capacity = rh->capacity;

	rh->data = h->data;
	rh->size = h->size;
	rh->capacity = h->capacity;

	deleteVector(h);
}

void reserve(Vector* v, size_t newCap)
{
	if (newCap <= v->capacity)
		return;

	v->capacity = (v->capacity == 0) ? 1 : v->capacity;
	while (v->capacity < newCap) {
		v->capacity *= 2;
	}

	if (v->data == nullptr)
		v->data = new int[v->capacity];
	else
	{
		int* newData = new int[v->capacity];
		memcpy(newData, v->data, v->size * sizeof(int));
		v->data = newData;
	}
}

int getValue(Vector* v, size_t index)
{
	assert(index < v->size);
	return v->data[index];
}

size_t getSize(Vector* v)
{
	return v->size;
}

size_t getCapacity(Vector* v)
{
	return v->capacity;
}

void append(Vector* v, int value)
{
	reserve(v, v->size + 1);

	v->data[v->size] = value;
	v->size++;
}

void append(Vector* v, int* array, size_t count)
{
	for (size_t i = 0; i < count; i++)
		append(v, array[i]);
}

void insert(Vector* v, size_t index, int value)
{
	reserve(v, v->size + 1);

	for (size_t i = v->size; i > index; i--)
		v->data[i] = v->data[i - 1];

	v->size++;
	v->data[index] = value;
}

void erase(Vector* v, size_t index)
{
	for (size_t i = index; i < v->size; i++)
		v->data[i] = v->data[i + 1];

	v->size--;
}

size_t indexOf(Vector* v, int value)
{
	for (size_t i = 0; i < v->size; i++) {
		if (v->data[i] == value)
			return i;
	}
	return -1;
}

void squeeze(Vector* v)
{
	if (v->size == 0)
		delete[] v->data;
	else
	{
		int* newData = new int[v->size];
		memcpy(newData, v->data, v->size * sizeof(int));
		v->data = newData;
		v->capacity = v->size;
	}
}

void clear(Vector* v)
{
	for (size_t i = 0; i < v->size; i++)
		v->data[i] = 0;

	v->size = 0;
}

void print(Vector* v)
{
	for (size_t i = 0; i < v->size - 1; i++)
		std::cout << getValue(v, i) << ", ";

	std::cout << getValue(v, v->size - 1) << "\n";
}