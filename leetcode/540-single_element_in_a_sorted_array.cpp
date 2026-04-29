#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int singleNonDuplicate(vector<int> &nums)
	{
		// we have to track the change in pattern
		// usually, <1, 1> -> first is at even index, second is at odd index
		// after single number, <3, 3> -> first is at odd index, second is at
		// even index

		int n = nums.size();

		// Handle Edge Cases immediately
		if (n == 1)
			return nums[0];
		if (nums[0] != nums[1])
			return nums[0];
		if (nums[n - 1] != nums[n - 2])
			return nums[n - 1];

		// Search in the range [1, n-2] to avoid index out of bounds
		int left = 1, right = n - 2;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			// mid is the unique element
			if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
				return nums[mid];

			// disruption to the left
			else if ((mid % 2 == 0 && nums[mid - 1] == nums[mid]) ||
			         (mid % 2 != 0 && nums[mid] == nums[mid + 1]))
				right = mid - 1;
			// disruption to the rigt
			else
				left = mid + 1;
		}

		// shouldnt reach here at all
		return nums[0];
	}
};

int main()
{
	Solution soln;
	vector<int> a = {1, 2, 2, 3, 3};
	cout << soln.singleNonDuplicate(a);
	return 0;
}
