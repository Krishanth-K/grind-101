#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int longestSubarray(vector<int> &nums)
	{
		int n = nums.size();
		int slow = 0, fast = 0;
		int non1Count = 0;
		int count = 0;

		for (int fast = 0; fast < n; fast++)
		{
			if (nums[fast] != 1)
				non1Count++;

			if (non1Count > 1)
			{
				if (nums[slow] != 1)
					non1Count--;
				slow++;
			}

			count = std::max(count, fast - slow + 1);
		}

		return count - 1;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {0, 1, 1, 1, 0, 1, 1, 0, 1};
	cout << soln.longestSubarray(a);
	return 0;
}
