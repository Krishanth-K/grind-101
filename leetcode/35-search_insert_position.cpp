#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int searchInsert(vector<int> &nums, int target)
	{
		int left = 0, right = nums.size() - 1;

		while (left <= right)
		{
			// this prevents integer overflow
			int mid = left + (right - left) / 2;

			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid - 1;
		}

		return left;
	}
};

int main()
{
	Solution soln;
	return 0;
}
