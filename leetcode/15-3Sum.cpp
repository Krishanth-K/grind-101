// tag
// tag arrays

// diff: med

// url: https://leetcode.com/problems/3sum/

#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

// algorithm:
// fix a number
// start (left, right) from (fix+1, end)
// apply two-sum-two to this.
// skip duplicates in the outer and inner level

class Solution {
  public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		if (nums.size() < 3)
			return {};

		vector<vector<int>> result;

		// sort
		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++)
		{
			// early termination
			if (nums[i] > 0)
				return result;

			// fix a num, then apply two-sum-two logic to get -fixed
			int fixed = nums[i];
			int target = -1 * fixed;

			// safety check when duplicates exist
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			int left = i + 1;
			int right = nums.size() - 1;

			while (left < right)
			{
				int sum = nums[left] + nums[right];

				if (sum == target)
				{
					result.push_back({nums[i], nums[left], nums[right]});

					int current_left = left;
					while (left < right && nums[left] == nums[current_left])
						left++;
				}
				else if (sum < target)
					left++;
				else
					right--;
			}
		}

		return result;
	}
};

int main()
{
	Solution soln;
	return 0;
}
