#include <iostream>

struct EmployeeFirst
{
	double salary;
	char name[7];
	int age;
	short id;
	bool experience;
};

struct EmployeeSecond
{
	double salary;
	bool experience;
	int age;
	char name[7];
	short id;
};

#pragma pack(push, 1)
struct EmployeeThird
{
	double salary;
	bool experience;
	int age;
	char name[7];
	short id;
};
#pragma pack(pop)

template <typename T>
void sizeOfAllFiled(T& employee)
{
	std::cout << "Сумма всех полей структуры:" << std::endl
		<< sizeof(employee.id) + sizeof(employee.age) + sizeof(employee.experience)
		+ sizeof(employee.name) + sizeof(employee.salary) << std::endl;
}

template <typename T>
void sizeOfStruct(T& employee)
{
	std::cout << "Размер структуры:" << std::endl
		<< sizeof(employee) << std::endl;
}

template <typename T>
void showAddressesInMemory(T& employee)
{
	std::cout << "Адреса в памяти:" << std::endl
		<< &(employee.id) << " " << &(employee.age) << " "
		<< &(employee.experience) << " " << &(employee.name) 
		<< " " << &(employee.salary) << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	EmployeeFirst first;
	std::cout << "ПЕРВАЯ СТРУКТУРА" << std::endl;
	sizeOfAllFiled(first);
	sizeOfStruct(first);
	showAddressesInMemory(first);
	std::cout << std::endl;

	EmployeeSecond second;
	std::cout << "ВТОРАЯ СТРУКТУРА" << std::endl;
	sizeOfAllFiled(second);
	sizeOfStruct(second);
	showAddressesInMemory(second);
	std::cout << std::endl;

	EmployeeThird third;
	std::cout << "ТРЕТЬЯ СТРУКТУРА" << std::endl;
	sizeOfAllFiled(third);
	sizeOfStruct(third);
	showAddressesInMemory(third);
	std::cout << std::endl;

	return 0;
}