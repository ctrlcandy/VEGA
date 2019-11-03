#include <iostream>

int** create(int size)
{
	int** matrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}

	return matrix;
}

void print(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << "\n";
	}

}

void fill(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				matrix[i][j] = 3;
			if (i > j)
				matrix[i][j] = 1;
			if (i < j)
				matrix[i][j] = 2;
		}
	}
}

void remove(int** matrix, int rows)
{
	if (matrix != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите размер матрицы:" << std::endl;
	int size;
	std::cin >> size;

	int** matrix = create(size);
	fill(matrix, size);
	print(matrix, size);

	remove(matrix, size);

	return 0;
}