#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<vector<int>> fourSum(vector<int> &nums, int target)
	{
		int n = nums.size();
		std::sort(nums.begin(), nums.end());

		vector<vector<int>> res = {};

		// fix two numbers and apply 2 sum logic
		for (int i = 0; i < n - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			// --- PRUNING FOR i ---
			// If the smallest 4 sum is > target, i is too large. Break.
			if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] >
			    target)
				break;
			// If the largest 4 sum with this i is < target, i is too small.
			// Skip.
			if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] <
			    target)
				continue;

			for (int j = i + 1; j < n - 2; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;

				// --- PRUNING FOR j ---
				if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] >
				    target)
					break;
				if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] <
				    target)
					continue;

				// 2 sum
				int left = j + 1;
				int right = n - 1;

				// cast to long long to prevent overflow
				long long remaining = (long long)target - nums[i] - nums[j];

				while (left < right)
				{
					int sum = nums[left] + nums[right];
					if (sum == remaining)
					{
						res.push_back(
						    {nums[i], nums[j], nums[left], nums[right]});

						// Skip duplicates for 3rd and 4th numbers
						while (left < right && nums[left] == nums[left + 1])
							left++;
						while (left < right && nums[right] == nums[right - 1])
							right--;

						left++;
						right--;
					}
					else if (sum < remaining)
						left++;
					else
						right--;
				}
			}
		}

		return res;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {2, 2, 2, 2, 2};
	soln.fourSum(a, 8);
	return 0;
}
