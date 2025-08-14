// tag
// tag recursion

// diff: easy

// url:
// https://leetcode.com/problems/power-of-three/?envType=daily-question&envId=2025-08-13

#include "utils/vec.hpp"
#include <iostream>
using std::cout, std::endl, utils::vector;

bool isPowOfThree(int n)
{
	// early return cases
	if (n == 1)
		return true;
	if (n % 3 != 0 || n == 0 || n < 0)
		return false;

	while (n > 1)
	{
		n /= 3;

		if (n == 1)
			return true;

		if (n % 3 != 0)
			return false;
	}

	return true;
}

bool bestSoln(int n)
{
	if (n <= 0)
		return false;

	while (n % 3 == 0)
		n /= 3;

	return n == 1;
}

class Solution {
  public:
	bool isPowerOfThree(int n)
	{
		// return isPowOfThree(n);
		return bestSoln(n);
	}
};

int main()
{
	Solution soln;

	cout << soln.isPowerOfThree(27);
	return 0;
}
