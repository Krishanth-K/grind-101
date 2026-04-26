#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

// Fast I/O block is mandatory for 99% beats on LeetCode
static const int speedup = []() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
  public:
	int maximumBeauty(vector<int> &nums, int k)
	{
		int n = nums.size();
		int slow = 0, fast = 0;
		int size = 0;

		std::sort(nums.begin(), nums.end());

		for (fast = 0; fast < n; fast++)
		{
			if (nums[fast] - nums[slow] > 2 * k)
				slow++;

			// size = std::max(size, fast - slow + 1);
		}

		return fast - slow;
	}
};

int main()
{
	Solution soln;
	return 0;
}
