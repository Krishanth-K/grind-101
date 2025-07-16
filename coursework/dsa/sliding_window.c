#include <stdio.h>

int slide(int arr[], int size)
{
	int max_length = 0;
	int index = 0;

	/* int size = sizeof(arr) / sizeof(arr[0]); */

	for (int i = 0; i < size; i++)
	{
		int j = i;
		int temp = 0;

		while ((arr[j] < arr[j + 1]) && j < size)
		{
			j++;
			temp += 1;
		}

		if (temp >= max_length)
		{
			max_length = temp;
			index = i;
		}

		// fallback condition if arr[j] >= arr[j+1]
		if (i == j)
			i = j + 1;
		else
			i = j;
	}

	return max_length + 1;
}

int main()
{
	int arr[10] = {1, 5, 9, 3, 7, 2, 1, 5, 6, 7};
	int length = slide(arr, 10);
	printf("%d", length);
}
