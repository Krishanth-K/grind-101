#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char *ans = NULL;

bool append(char **ptr, char letter, int *size)
{
	// Increment size first
	(*size)++;

	// Then reallocate for the new size
	*ptr = (char *)realloc(*ptr, sizeof(char) * (*size));
	if (*ptr == NULL)
	{
		printf("realloc error\n");
		return false;
	}

	// Now use the correct indexing
	(*ptr)[*size - 2] = letter; // Place letter at second-to-last position
	(*ptr)[*size - 1] = '\0';   // Place null terminator at last position

	return true;
}

char *revString(char *ptr, int size)
{
	int strLen = size - 1;
	char *rev = malloc(size * sizeof(char));
	if (!rev)
	{
		printf("malloc error in revString\n");
		return NULL;
	}

	for (int i = 0; i < strLen; i++)
	{
		rev[i] = ptr[strLen - 1 - i];
	}
	rev[strLen] = '\0';
	free(ptr);
	return rev;
}

char *convertToTitle(int columnNumber)
{
	int size = 1; // Initialize size properly

	// Create the initial string
	ans = (char *)malloc(1);
	if (!ans)
	{
		printf("Malloc failure\n");
		return NULL;
	}
	ans[0] = '\0';

	while (columnNumber > 0)
	{
		// Find the char offset from 'A'
		int offset = (columnNumber - 1) % 26;
		// Find the new col number
		columnNumber = (columnNumber - 1) / 26;
		char letter = (char)(offset + 65);

		// Add the letter to the end of string
		if (!append(&ans, letter, &size))
		{
			return NULL;
		}
	}

	// Reverse the string
	ans = revString(ans, size);
	return ans;
}

int main()
{
	char *result = convertToTitle(27);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	return 0;
}
