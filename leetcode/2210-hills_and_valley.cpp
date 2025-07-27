// link:
// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description

#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
	int countHillValley(vector<int> &nums)
	{
		int n = nums.size();

		// sum of hills and valleys
		int sum = 0;

		for (int i = 1; i < n - 1; i++)
		{
			int neighbors = 0;
			int l = i - 1;
			int r = i + 1;

			// move left until finding a non-equal neighbor on the left
			while (nums[l] == nums[i] && l > 0)
				l--;

			// move right until finding a non-equal neighbor on the right
			while (nums[r] == nums[i] && r < n - 1)
			{
				r++;

				// keep track of equal neighbors as they belong to the same
				// hill/valley
				neighbors++;
			}

			if ((nums[l] < nums[i] && nums[r] < nums[i]) ||
			    (nums[l] > nums[i] && nums[r] > nums[i]))
				sum += 1;

			// skip equal neighbors (they belong to same hill/valley)
			i += neighbors;
		}

		return sum;
	}
};

int main()
{
	Solution soln;
	std::vector<int> arr{2, 4, 1, 1, 6, 5};

	std::cout << soln.countHillValley(arr);
}
