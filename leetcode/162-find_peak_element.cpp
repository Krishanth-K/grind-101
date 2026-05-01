#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int findPeakElement(vector<int> &nums)
	{
		// for a peak element to be present, the array shouldn't be
		// increasing or decreasing
		// So ignore the half that is increasing/decreasing
		int n = nums.size();

		if (n == 1)
			return 0;

		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;

			// potential upward slope to the right
			if (nums[mid + 1] > nums[mid])
				left = mid + 1;

			// potential upward slope to the left
			else
				right = mid;
		}

		return right;
	}
};

int main()
{
	Solution soln;
	return 0;
}
