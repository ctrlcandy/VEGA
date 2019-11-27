#include <iostream>
#include <time.h>

void makeStartingField(std::string filed[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			filed[i][j] = "*";
			std::cout << filed[i][j] << " ";
		}
		std::cout << "\n";
	}
}

bool gameIsContinue(int x, int y, std::string filed[3][3])
{	
	// проверка строчки столбца
	if ((filed[0][0] == filed[0][1] && filed[x][0] == filed[x][2] && filed[x][1] == filed[x][2])
	||  (filed[0][y] == filed[1][y] && filed[0][y] == filed[2][y] && filed[1][y] == filed[2][y]))
		return false;

	// проверка диагоналей
	else if (filed[1][1] != "*")
	{
		if ((filed[1][1] == filed[0][0] && filed[1][1] == filed[2][2] && filed[0][0] == filed[2][2])
		||  (filed[1][1] == filed[0][2] && filed[1][1] == filed[2][0] && filed[0][2] == filed[2][0]))
			return false;
	}

	return true;
}

void print(std::string filed[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << filed[i][j] << " ";
		std::cout << "\n";
	}
}

void add(int x, int y, std::string var, std::string filed[3][3])
{
	if (filed[x][y] == "*" && (x < 3) && (y < 3))
	{
		filed[x][y] = var;
	}
}

void play()
{
	std::string filed[3][3];
	makeStartingField(filed);

	bool check = true;
	int x1, y1;
	int count = 0;

	srand(time(0));

	while (check)
	{
		count++;

		std::cin >> x1 >> y1;
		x1--;
		y1--;

		add(x1, y1, "X", filed);
		if (gameIsContinue(x1, y1, filed) == false)
			break;

		int x2 = 0;
		int y2 = 0;
		while (filed[x2][y2] != "*" and count != 9)
		{
			x2 = rand() % 3;
			y2 = rand() % 3;
		}
		add(x2, y2, "O", filed);
		check = gameIsContinue(x2, y2, filed);

		print(filed);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите координаты клетки, чтобы начать." << std::endl;
	play();

	return 0;
}