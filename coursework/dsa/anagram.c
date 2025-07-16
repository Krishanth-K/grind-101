#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char *s, char *t)
{
	int char_array[26] = {0};

	int length1 = strlen(s);
	int length2 = strlen(t);

	if (length1 != length2)
	{
		printf("Not anagrams");
		return false;
	}

	for (int i = 0; i < length1; i++)
	{
		int offset = s[i] - 'a';
		char_array[offset]++;
	}

	for (int i = 0; i < length1; i++)
	{
		int offset = t[i] - 'a';
		if (char_array[offset] == 0)
		{
			printf("Not anagrams");
			return false;
		}

		char_array[offset]--;
	}

	printf("anagrams");
	return true;
}

int main()
{
	char *a = "car";
	char *b = "rac";

	isAnagram(a, b);

	return 0;
}
