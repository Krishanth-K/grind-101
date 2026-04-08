// diff: medium

#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	void sortColors(vector<int> &nums)
	{
		int low = 0;                // Boundary for 0s
		int mid = 0;                // Current element being inspected
		int high = nums.size() - 1; // Boundary for 2s

		while (mid <= high)
		{
			if (nums[mid] == 0)
			{
				std::swap(nums[low], nums[mid]);
				low++;
				mid++;
			}
			else if (nums[mid] == 1)
				mid++;
			else
			{ // nums[mid] == 2
				std::swap(nums[mid], nums[high]);
				high--;
			}
		}
	}
};

int main()
{
	Solution soln;
	vector<int> a = {1, 0, 1};
	soln.sortColors(a);
	for (int x : a)
		std::cout << x << ' ';
	return 0;
}
