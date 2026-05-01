#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	bool search(vector<int> &nums, int target)
	{
		int left = 0, right = nums.size() - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return true;

			// THE CRITICAL ADDITION:
			// If we can't tell which half is sorted because of duplicates
			if (nums[left] == nums[mid] && nums[mid] == nums[right])
			{
				left++;
				right--;
				continue; // Skip the rest of the logic and re-calculate mid
			}

			// Normal logic from version I
			if (nums[left] <= nums[mid])
			{
				if (target >= nums[left] && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else
			{
				if (target > nums[mid] && target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return false;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {3, 1};
	cout << soln.search(a, 1);
	return 0;
}
