#include <iostream>

int** createMatrix(int row, int col) 
{
	int** matrix = new int* [row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	return matrix;
}

void initializeMatrix (int row, int col, int **matrix)
{
	int num;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cin >> num;
			matrix[i][j] = num;
		}
	}
}

void matrixMultiplication(int rowFirst, int colFirst, int rowSecond, int colSecond, int** firstMatrix, int** secondMatrix)
{
	if (colFirst != rowSecond)
	{
		std::cout << "Error" << std::endl;
	}
	else
	{
		int length = colFirst;
		int row = rowFirst;
		int col = colSecond;

		int** newMatrix = new int* [row];
		for (int i = 0; i < row; i++)
			newMatrix[i] = new int[col];

		for (int i = 0; i < row; i++) 
		{
			for (int j = 0; j < col; j++) 
			{
				newMatrix[i][j] = 0;
				for (int k = 0; k < length; k++) 
				{
					newMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
				}
				std::cout << newMatrix[i][j] << " ";
			}
		}
	}	

}


int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "������� ������ 1-�� �������:" << std::endl;
	int rowFirst, colFirst;
	std::cin >> rowFirst >> colFirst;
	std::cout << "������� �������� 1-�� �������:" << std::endl; 
	int **firstMatrix = createMatrix(rowFirst, colFirst);
	initializeMatrix(rowFirst, colFirst, firstMatrix);

	std::cout << "������� ������ 2-�� �������:" << std::endl;
	int rowSecond, colSecond;
	std::cin >> rowSecond >> colSecond;
	std::cout << "������� �������� 2-�� �������:" << std::endl;
	int** secondMatrix = createMatrix(rowSecond, colSecond);
	initializeMatrix(rowSecond, colSecond, secondMatrix);

	matrixMultiplication(rowFirst, colFirst, rowSecond, colSecond, firstMatrix, secondMatrix);
	
	return 0;
}