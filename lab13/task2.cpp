#include <iostream>

void printArrayAddresses(int* arr, const int size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << &(arr[i]) << std::endl;
}


int main()
{
	const int size = 3;
	setlocale(LC_ALL, "Russian");

	std::cout << "Статический одномерный массив:" << std::endl;
	int staticArray[size];
	printArrayAddresses(staticArray, size);

	std::cout << "Статический двумерный массив:" << std::endl;
	int staticMatrix[size][size];
	for (size_t i = 0; i < size; i++)
			printArrayAddresses(staticMatrix[i], size);

	std::cout << "Динамический одномерный массив:" << std::endl;
	int* dynamicArray = new int[size];
	printArrayAddresses(dynamicArray, size);

	std::cout << "Динамический двумерный массив:" << std::endl;
	int** dynamicMatrix = new int* [size];
	for (size_t i = 0; i < size; i++)
		dynamicMatrix[i] = new int[size];

	for (size_t i = 0; i < size; i++)
		printArrayAddresses(dynamicMatrix[i], size);

	return 0;
}