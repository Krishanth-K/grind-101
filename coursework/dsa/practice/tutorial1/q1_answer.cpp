#include <iostream>
#include <vector>

void swap(std::vector<char> &arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

std::vector<char> sort(std::vector<char> &arr)
{
	int n = arr.size();

	// convert char to numbers
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 'c')
			arr[i] = 0;
		if (arr[i] == 'o')
			arr[i] = 2;
		if (arr[i] == 'y')
			arr[i] = 1;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
		}
	}

	// convert numbers back to chars
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			arr[i] = 'c';
		if (arr[i] == 2)
			arr[i] = 'o';
		if (arr[i] == 1)
			arr[i] = 'y';
	}

	return arr;
}

int main()
{
	std::vector<char> arr = {'c', 'o', 'o', 'c', 'c', 'y', 'c', 'o', 'o'};
	arr = sort(arr);
	for (const auto i : arr)
		std::cout << i << ", ";
}
