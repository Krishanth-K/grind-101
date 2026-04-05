// diff: med

// url: https://leetcode.com/problems/3sum-closest/

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

// algorithm:
// fix a number
// start (left, right) from (fix+1, end)
// apply a MODIFIED two-sum-two to this.
// skip duplicates in the outer and inner level

class Solution {
  public:
	int threeSumClosest(vector<int> &nums, int target)
	{
		// sort
		std::sort(nums.begin(), nums.end());

		int n = nums.size();
		int closest_sum = nums[0] + nums[1] + nums[2];

		int largest_sum = nums[n - 1] + nums[n - 2] + nums[n - 3];
		int smallest_sum = nums[0] + nums[1] + nums[2];

		// early exit cases
		if (target < smallest_sum)
			return smallest_sum;
		if (target > largest_sum)
			return largest_sum;

		for (int i = 0; i < nums.size(); i++)
		{
			// safety check when duplicates exist
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			int left = i + 1;
			int right = n - 1;

			while (left < right)
			{
				int current_sum = nums[i] + nums[left] + nums[right];

				if (current_sum == target)
					return target;

				if (abs(target - current_sum) < abs(target - closest_sum))
					closest_sum = current_sum;

				if (current_sum < target)
					left++;
				else
					right--;
			}
		}

		return closest_sum;
	}
};

int main()
{
	Solution soln;
	return 0;
}
