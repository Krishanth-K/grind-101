// tag
// tag bit manipulation

// diff: medium

// url:
// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/

#include "utils/vec.hpp"
#include <iostream>
using std::cout, std::endl, utils::vector, std::string;

class Solution {
  public:
	int makeTheIntegerZero(int num1, int num2)
	{
		if (num2 > num1)
			return -1;

		int count = 0;

		while (num1 != 0)
		{
			count++;

			int diff = num1 - num2;

			int pow = 0;
			int powOfTwo = 1;

			while (diff / powOfTwo >= 1)
			{
				powOfTwo = powOfTwo << 1;
				pow++;
			}

			powOfTwo = powOfTwo >> 1;
			pow--;

			num1 = num1 - (powOfTwo + num2);
		}

		return count;

		// 10, 5 ;
		// 10 - (2 ^ i + 5) = 5 - 2 ^ i
	}
};

int main()
{
	Solution soln;

	cout << soln.makeTheIntegerZero(10, 5);
	return 0;
}
