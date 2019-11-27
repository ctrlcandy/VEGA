#include <iostream>
#include <cstring>

const char* trimStr(const char* str)
{
	size_t length = strlen(str) + 1;
	char* tmp = new char[length];
	size_t index = 0;

	for (size_t i = 0; i < length; i++)
	{
		if (str[i] != ' ')
		{
			tmp[index] = str[i];
			index++;

		}

		else if (index > 0)
			if (tmp[index - 1] != ' ')
			{
				tmp[index] = ' ';
				index++;
			}
	}

	if (tmp[index - 2] == ' ')
	{
		tmp[index - 2] = '\0';
		index--;
	}

	char* newStr = new char[index];
	memcpy(newStr, tmp, index);
	delete[] tmp;

	return newStr;
}

int main()
{
	std::cout << trimStr("   abc    ") << std::endl;
	std::cout << trimStr("   str   ") << std::endl;
	std::cout << trimStr(" a   b ") << std::endl;

	return 0;
}