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

void initialize(int rows, int cols, int** matrix)
{
	int num;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> num;
			matrix[i][j] = num;
		}
	}
}

void print(int rows, int cols, int** matrix)
{
	if (matrix != nullptr) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
	else
	{
		std::cout << "Error";
	}
}

void remove(int rows, int** matrix)
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

int** multiply(int rowsFirst, int colsFirst, int rowsSecond, int colsSecond, int** firstMatrix, int** secondMatrix)
{
	if (colsFirst != rowsSecond)
	{
		return nullptr;
	}
	else
	{
		int length = colsFirst;
		int rows= rowsFirst;
		int cols = colsSecond;

		int** newMatrix = create(rows, cols);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				newMatrix[i][j] = 0;
				for (int k = 0; k < length; k++)
				{
					newMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
				}
			}
		}
		return newMatrix;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите размер 1-ой матрицы:" << std::endl;
	int rowsFirst, colsFirst;
	std::cin >> rowsFirst >> colsFirst;
	std::cout << "Введите элементы 1-ой матрицы:" << std::endl;
	int** firstMatrix = create(rowsFirst, colsFirst);
	initialize(rowsFirst, colsFirst, firstMatrix);

	std::cout << "Введите размер 2-ой матрицы:" << std::endl;
	int rowsSecond, colsSecond;
	std::cin >> rowsSecond >> colsSecond;
	std::cout << "Введите элементы 2-ой матрицы:" << std::endl;
	int** secondMatrix = create(rowsSecond, colsSecond);
	initialize(rowsSecond, colsSecond, secondMatrix);

	int** newMatrix = multiply(rowsFirst, colsFirst, rowsSecond, colsSecond, firstMatrix, secondMatrix);
	print(rowsFirst, colsSecond, newMatrix);

	remove(rowsFirst, newMatrix);
	remove(rowsFirst, firstMatrix);
	remove(rowsSecond, secondMatrix);

	return 0;
}