// Given an array of arbitrary length L = |A|.
// This array has a sequence of number b/w 1 & L, in no particular
// order. Among those no.s in the sequence, a number is missing
// and a number is repeating.
// Find the missing and repeating numbers

#include <iostream>
#include <vector>

int getMissingAndRepeatingNumbers(std::vector<int> &arr)
{
	int n = arr.size() + 1;

	int actual_sum = 0;
	int actual_prod = 1;
	for (const int &e : arr)
	{
		actual_sum += e;
		actual_prod *= e;
	}

	int sum = (n * (n + 1)) / 2;

	std::cout << "sum: " << sum << std::endl;
	std::cout << "actual_sum: " << actual_sum << std::endl;

	return sum - actual_sum;
}

int main()
{
	std::vector<int> arr = {1, 2, 3, 4}; // n = 5, missing = 3
	std::cout << getMissingAndRepeatingNumbers(arr);
}
