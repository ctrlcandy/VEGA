#include <iostream>
#include <cstring>

size_t countCharInStr(const char *str, char ch)
{
	size_t count = 0;
	size_t length = strlen(str) + 1;
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == ch)
			count++;
	}
	
	return count;
}

int main()
{
	std::cout << countCharInStr("abcabcabc", 'a') << std::endl;
	std::cout << countCharInStr("abcabcabc", 'b') << std::endl;
	std::cout << countCharInStr("abcabcabc", 'c') << std::endl;
	std::cout << countCharInStr("abcabcabc", 'W') << std::endl;

	return 0;
}