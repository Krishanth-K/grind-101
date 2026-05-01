#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int search(vector<int> &nums, int target)
	{
		int n = nums.size();

		int left = 0, right = n - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return mid;

			// find which half is sorted
			// left half is sorted
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

		return -1;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {1, 3};
	cout << soln.search(a, 3);
	return 0;
}
