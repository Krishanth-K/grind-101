#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

// This block speeds up the judge's input/output processing
static const int speedup = []() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
  public:
	int maxFrequency(vector<int> &nums, int k)
	{
		// we must find a window, where the sum of differences with the largest
		// number <= k

		std::sort(nums.begin(), nums.end());
		int n = nums.size();

		int slow = 0, fast = 0;
		long long window_sum = 0;

		// geometric method
		for (fast = 0; fast < n; fast++)
		{
			window_sum += nums[fast];

			if ((long long)(nums[fast]) * (fast - slow + 1) - window_sum > k)
			{
				window_sum -= nums[slow];
				slow++;
			}
		}
		return fast - slow;

		// own method -> slower
		// long long sum_of_diffs = 0;
		// for (fast = 0; fast < n; fast++)
		// {
		//     if (fast - 1 >= 0)
		//     	sum_of_diffs +=
		//     	    (long long)(nums[fast] - nums[fast - 1]) * (fast -
		//     slow);
		//
		//     // shrink window
		//     if (nums[fast] * (fast - slow + 1)) - window_sum <= k ->
		//     valid
		//
		//     if (sum_of_diffs > k)
		//     {
		//     	sum_of_diffs -= nums[fast] - nums[slow];
		//     	slow++;
		//     }
		// }
		// return fast - slow;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {1, 4, 8, 13};
	cout << soln.maxFrequency(a, 5);
}
