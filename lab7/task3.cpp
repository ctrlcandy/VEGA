#include <iostream>

int** create(int rows, int cols)
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}

	return matrix;
}

void initialize(int size_rows, int size_cols, int** matrix)
{
	int num;
	for (int i = 0; i < size_rows; i++)
	{
		for (int j = 0; j < size_cols; j++)
		{
			std::cin >> num;
			matrix[i][j] = num;
		}
	}
}

void print(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
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

void swapRows(int** matrix, int size_rows, int size_cols, int row1, int row2)
{
	if (row1 > size_rows || row2 > size_rows)
	{
		std::cout << "Error" << std::endl;
	}
	else
	{
		int temp;
		row1--;
		row2--;
		for (int i = 0; i < size_cols; i++)
		{
			temp = matrix[row1][i];
			matrix[row1][i] = matrix[row2][i];
			matrix[row2][i] = temp;
		}
		print(matrix, size_rows, size_cols);
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите размер матрицы:" << std::endl;
	int size_rows, size_cols;
	std::cin >> size_rows >> size_cols;

	std::cout << "Введите элементы матрицы:" << std::endl;
	int** matrix = create(size_rows, size_cols);
	initialize(size_rows, size_cols, matrix);

	std::cout << "Введите индексы строк для перестановки:" << std::endl;
	int row1, row2;
	std::cin >> row1 >> row2;

	swapRows(matrix, size_rows, size_cols, row1, row2);

	remove(matrix, size_rows);

	return 0;
}

