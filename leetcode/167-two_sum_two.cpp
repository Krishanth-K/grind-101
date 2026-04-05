// tag
// tag two pointers

// diff: easy

// url: https://leetcode.com/problems/two-sum/

#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		int left = 0, right = nums.size() - 1;

		while (left < right)
		{
			int sum = nums[left] + nums[right];

			if (sum == target)
				return {left + 1, right + 1};
			else if (sum < target)
				left++;
			else
				right--;
		}

		return {};
	}
};

int main()
{
	Solution soln;
	return 0;
}
