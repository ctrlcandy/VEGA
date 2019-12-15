#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstring>
#include <cassert>

template <typename T>
struct Vector {
	T* data;
	size_t size;
	size_t capacity;
};

template <typename T>
Vector<T>* createVector()
{
	Vector<T>* v = new Vector<T>();

	v->data = nullptr;
	v->size = 0;
	v->capacity = 0;

	return v;
}

template <typename T>
void deleteVector(Vector<T>* v)
{
	delete[] v->data;
	delete v;
}

template <typename T>
Vector<T>* copyVector(Vector<T>* v)
{
	Vector<T>* newVector = new Vector<T>();
	newVector->size = v->size;
	newVector->capacity = v->capacity;

	newVector->data = new T[newVector->capacity];
	memcpy(newVector->data, v->data, v->size * sizeof(T));

	return newVector;
}

template <typename T>
void swapVector(Vector<T>* lh, Vector<T>* rh)
{
	Vector<T>* h = copyVector<T>(lh);
	lh->data = rh->data;
	lh->size = rh->size;
	lh->capacity = rh->capacity;

	rh->data = h->data;
	rh->size = h->size;
	rh->capacity = h->capacity;

	deleteVector<T>(h);
}

template <typename T>
void reserve(Vector<T>* v, size_t newCap)
{
	if (newCap <= v->capacity)
		return;

	v->capacity = (v->capacity == 0) ? 1 : v->capacity;
	while (v->capacity < newCap) {
		v->capacity *= 2;
	}

	if (v->data == nullptr)
		v->data = new T[v->capacity];
	else
	{
		T* newData = new T[v->capacity];
		memcpy(newData, v->data, v->size * sizeof(T));
		v->data = newData;
	}
}

template <typename T>
T getValue(Vector<T>* v, size_t index)
{
	assert(index < v->size);
	return v->data[index];
}

template <typename T>
size_t getSize(Vector<T>* v)
{
	return v->size;
}

template <typename T>
size_t getCapacity(Vector<T>* v)
{
	return v->capacity;
}

template <typename T>
void append(Vector<T>* v, T value)
{
	reserve(v, v->size + 1);

	v->data[v->size] = value;
	v->size++;
}

template <typename T>
void insert(Vector<T>* v, size_t index, T value)
{
	reserve<T>(v, v->size + 1);

	for (size_t i = v->size; i > index; i--)
		v->data[i] = v->data[i - 1];

	v->size++;
	v->data[index] = value;
}

template <typename T>
void erase(Vector<T>* v, size_t index)
{
	for (size_t i = index; i < v->size; i++)
		v->data[i] = v->data[i + 1];

	v->size--;
}

template <typename T>
int indexOf(Vector<T>* v, T value)
{
	for (size_t i = 0; i < v->size; i++) {
		if (v->data[i] == value)
			return i;
	}
	return -1;
}

template <typename T>
void squeeze(Vector<T>* v)
{
	if (v->size == 0)
		delete[] v->data;
	else
	{
		T* newData = new T[v->size];
		memcpy(newData, v->data, v->size * sizeof(T));
		v->data = newData;
		v->capacity = v->size;
	}
}

template <typename T>
void clear(Vector<T>* v)
{
	for (size_t i = 0; i < v->size; i++)
		v->data[i] = 0;

	v->size = 0;
}

template <typename T>
void print(Vector<T>* v)
{
	for (size_t i = 0; i < v->size - 1; i++)
		std::cout << getValue<T>(v, i) << ", ";

	std::cout << getValue<T>(v, v->size - 1) << "\n";
}

#endif // VECTOR_H