#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector;

// dp[0] = money from just house 0
// dp[1] = best money from houses 0 and 1
// dp[2] = best money from houses 0, 1, and 2
// dp[3] = best money from houses 0, 1, 2, and 3

// Notes = (../../notes/grind/dynamicProg/index.md)

class Solution {
  public:
	int rob(vector<int> &nums)
	{
		// array length
		int n = nums.size();

		if (n == 0)
			return 0;
		if (n == 1)
			return nums[0];

		// vector to store the best_soln
		vector<int> best_soln(n, 0);

		// set up the best solns for first two houses
		best_soln[0] = nums[0];
		best_soln[1] = std::max(nums[0], nums[1]);

		for (int i = 2; i < n; i++)
		{
			best_soln[i] =
			    std::max(best_soln[i - 1], nums[i] + best_soln[i - 2]);
		}

		// return the best_soln for the last house
		return best_soln[n - 1];
	}
};

int main()
{
	Solution soln;
	std::vector<int> nums = {2, 7, 9, 3, 1};

	cout << soln.rob(nums);
}
