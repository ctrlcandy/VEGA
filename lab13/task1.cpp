#include <iostream>

int global;

int main()
{
	setlocale(LC_ALL, "Russian");

	int local;
	int* dynamic = new int;

	std::cout << "Адрес глобальной переменной: " << &global << std::endl
		<< "Адрес автоматической переменной: " << &local << std::endl
		<< "Адрес динамической переменной: " << dynamic;

	return 0;
}