// tag
// tag arrays

// diff: medium

// url: https://leetcode.com/problems/number-of-zero-filled-subarrays/

#include "utils/vec.hpp"
#include <iostream>
using std::cout, std::endl, utils::vector, std::string;

class Solution {
  public:
	long long zeroFilledSubarray(vector<int> &nums)
	{
		long long zeroCount = 0;
		long long result = 0;

		for (const auto &a : nums)
		{
			if (a == 0)
				zeroCount++;

			else if (a != 0 && zeroCount != 0)
			{
				result += zeroCount * (zeroCount + 1) * 0.5;
				zeroCount = 0;
			}
		}

		result += zeroCount * (zeroCount + 1) * 0.5;

		return result;
	}
};

int main()
{
	Solution soln;
	return 0;
}
