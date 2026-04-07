// diff: easy

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<int> sortedSquares(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> result(n, 0);

		int left = 0;
		int right = n - 1;
		int idx = n - 1;

		while (idx >= 0)
		{
			if (abs(nums[left]) > abs(nums[right]))
			{
				result[idx] = nums[left] * nums[left];
				left++;
			}
			else
			{
				result[idx] = nums[right] * nums[right];
				right--;
			}
			idx--;
		}

		return result;
	}
};

int main()
{
	Solution soln;
	return 0;
}
