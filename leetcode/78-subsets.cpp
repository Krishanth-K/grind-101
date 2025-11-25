// tag
// tag subset

// diff: medium

// url: https://leetcode.com/problems/subsets/

#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<vector<int>> subsets(vector<int> &nums)
	{
		int n = nums.size();
		vector<vector<int>> res;

		for (int i = 0; i < 1 << n; i++)
		{
			vector<int> subset;
			for (int j = 0; j < n; j++)
			{
				if (i & 1 << j)
					subset.push_back(nums[j]);
			}

			res.push_back(subset);
		}

		return res;
	}
};

int main()
{
	Solution soln;
	return 0;
}
