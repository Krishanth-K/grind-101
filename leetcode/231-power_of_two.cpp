// tag

// diff: easy

// url:
// https://leetcode.com/problems/power-of-two/?envType=daily-question&envId=2025-08-09

#include <climits>
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

class Solution {
  public:
	bool isPowerOfTwo(int n)
	{
		// early return cases
		if (n == 1)
			return true;
		if (n % 2 != 0 || n == 0)
			return false;
		if (n < 0)
			return false;

		while (n >= 0)
		{
			// divide n by 2
			n = n >> 1;

			if (n == 1)
				return true;
			if (n % 2 != 0 || n == 0)
				return false;
		}

		return true;
	}
};

int main()
{
	Solution soln;

	int a = 16;

	while (a >= 0)
		cout << a << endl;

	return 0;
}
