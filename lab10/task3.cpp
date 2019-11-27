#include <iostream>
#include <cstring>

void alphabetSort(char** str, size_t count)
{
	char* tmp;
	for (int i = 0; i < count - 1; i++)
		for (int j = 0; j < count - i - 1; j++)
			if (strcmp(str[j], str[j + 1]) > 0)
			{
				tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp;
			}
}


int main()
{
	char* stringsFirst[] = { (char*)"ecd", (char*)"bcd", (char*)"abc" };
	alphabetSort(stringsFirst, 3);

	char* stringsSecond[] = { (char*)"Man", (char*)"who", (char*)"sold", (char*)"the", (char*)"world" };
	alphabetSort(stringsSecond, 5);

	return 0;
}