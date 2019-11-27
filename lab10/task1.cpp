#include <iostream>
#include <cstring>


const char* toUpperCase(const char *str)
{
	size_t length = strlen(str) + 1;
	char *newStr = new char[length];

	for (size_t i = 0; i < length; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			newStr[i] = str[i] - 32;
		else
			newStr[i] = str[i];
	}

	return newStr;
}

int main()
{
	std::cout <<  toUpperCase("HeLlO WoRld!!1111") << std::endl;
	std::cout << toUpperCase("abcabcabc") << std::endl;

	return 0;
}