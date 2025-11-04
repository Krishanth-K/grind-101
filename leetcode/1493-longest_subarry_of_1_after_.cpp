// tag
// tag array

// diff: medium

// url:
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

#include "utils/vec.hpp"
#include <iostream>
using std::cout, std::endl, utils::vector, std::string;

class Solution {
  public:
	int longestSubarray(vector<int> &nums)
	{
		int currentSize = 0, maxSize = 0;
		int nextStart = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 1)
				currentSize++;
			else if (nums[i] == 0 && currentSize > 0)
			{
				if (i + 1 < nums.size() && nums[i + 1] == 1)
					currentSize++;
			}
		}
		return maxSize;
	}
};

int main()
{
	Solution soln;
	return 0;
}
