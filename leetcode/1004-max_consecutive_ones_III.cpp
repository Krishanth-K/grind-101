#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int longestOnes(vector<int> &nums, int k)
	{
		int n = nums.size();
		int slow = 0, fast = 0;
		int zeroCount = 0;
		int count = 0;

		for (int fast = 0; fast < n; fast++)
		{
			if (nums[fast] == 0)
				zeroCount++;

			// shrink window once -> so max window size is preserved
			// we only check for larger possible windows, not smaller ones
			if (zeroCount > k)
			{
				if (nums[slow] == 0)
					zeroCount--;
				slow++;
			}

			if (zeroCount <= k)
				count = std::max(count, fast - slow + 1);
		}

		return count;
	}
};

int main()
{
	Solution soln;
	return 0;
}
