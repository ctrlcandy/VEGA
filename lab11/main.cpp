#include <iostream>

#include "vector.h"

int main()
{
	Vector* v = createVector();

	std::cout << "append: " << std::endl;

	for (int i = 0; i < 10; i++)
	{
		append(v, i);

		std::cout << "value: " << getValue(v, i)
			<< " size: " << getSize(v)
			<< " capacity: " << getCapacity(v) << std::endl;
	}

	int pos = 3, val = 15;

	std::cout << "insert(" << pos << ", " << val << "):\n";
	insert(v, pos, val);
	print(v);

	std::cout << "erase(" << pos << "):\n";
	erase(v, pos);
	print(v);

	int newCap = 20;
	std::cout << "capacity: " << getCapacity(v) << std::endl;
	reserve(v, newCap);
	std::cout << "reserve(" << newCap << "): "
		<< "capacity: " << getCapacity(v) << std::endl;

	std::cout << "squeeze: ";
	squeeze(v);
	std::cout << "capacity: " << getCapacity(v) << std::endl;

	deleteVector(v);

	return 0;
}

// Вывод:
// 
// append: 
// value: 0 size: 1 capacity: 1
// value: 1 size: 2 capacity: 2
// value: 2 size: 3 capacity: 4
// value: 3 size: 4 capacity: 4
// value: 4 size: 5 capacity: 8
// value: 5 size: 6 capacity: 8
// value: 6 size: 7 capacity: 8
// value: 7 size: 8 capacity: 8
// value: 8 size: 9 capacity: 16
// value: 9 size: 10 capacity: 16
// insert(3, 15):
// 0 1 2 15 3 4 5 6 7 8 9 
// erase(3):
// 0 1 2 3 4 5 6 7 8 9 
// capacity: 16
// reserve(20): capacity: 32
// squeeze: capacity: 10