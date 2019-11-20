#include <iostream>
#include <cassert>

#include "vector.h"

static int* data = nullptr;
static size_t size = 0;
static size_t capacity = 0;

void reserve(size_t newCap)
{
	if (newCap <= capacity)
		return;

	capacity = (capacity == 0) ? 1 : capacity;
	while (capacity < newCap) {
		capacity *= 2;
	}

	if (data == nullptr)
		data = new int[capacity];
	else
	{
		int* newData = new int[capacity];
		memcpy(newData, data, size * sizeof(int));
		data = newData;
	}
}

int getValue(size_t index)
{
	assert(index < size);
	return data[index];
}

size_t getSize()
{
	return size;
}

size_t getCapacity()
{
	return capacity;
}

void append(int value)
{
	reserve(size + 1);

	data[size] = value;
	size++;
}

void append(int* array, size_t count)
{
	for (size_t i = 0; i < count; i++)
		append(array[i]);
}

void insert(size_t index, int value)
{
	reserve(size + 1);

	for (size_t i = size; i > index; i--)
		data[i] = data[i - 1];

	size++;
	data[index] = value;
}

void erase(size_t index)
{
	for (size_t i = index; i < size; i++)
		data[i] = data[i + 1];

	size--;
}

int indexOf(int value)
{
	int index = -1;
	for (size_t i = 0; i < size; i++) {
		if (data[i] == value)
			return i;
	}
	return -1;
}

void squeeze()
{
	if (size == 0)
		delete[] data;
	else
	{
		int* newData = new int[size];
		memcpy(newData, data, size * sizeof(int));
		data = newData;
		capacity = size;
	}
}

void clear()
{
	for (size_t i = 0; i < size; i++)
		data[i] = 0;

	size = 0;
}

void print()
{
	for (size_t i = 0; i < size - 1; i++)
		std::cout << getValue(i) << ", ";

	std::cout << getValue(size - 1) << "\n";
}