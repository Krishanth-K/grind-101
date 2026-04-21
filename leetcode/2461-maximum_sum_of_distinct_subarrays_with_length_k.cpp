#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	long long maximumSubarraySum(vector<int> &nums, int k)
	{
		int n = nums.size();

		if (n < k)
			return std::accumulate(nums.begin(), nums.end(), 0);

		int slow = 0;
		long long sum = 0;
		long long max_sum = 0;

		std::unordered_map<int, int> last_seen;

		// always points to the latest duplicate number
		// if the latest duplicate is out of the window, then the window has no
		// duplicates
		int last_seen_idx = -1;

		for (int fast = 0; fast < n; fast++)
		{
			// update sum
			sum += nums[fast];

			// nums[fast] is already seen
			if (last_seen.find(nums[fast]) != last_seen.end())
				last_seen_idx = std::max(last_seen_idx, last_seen[nums[fast]]);

			// update last seen to the latest index
			last_seen[nums[fast]] = fast;

			// shrink if size larger than k
			if (fast - slow + 1 > k)
			{
				sum -= nums[slow];
				slow++;
			}

			// no duplicates & calculate sum only for subarray of size = k
			if (slow > last_seen_idx && fast - slow + 1 == k)
				max_sum = std::max(max_sum, sum);
		}

		return max_sum;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {1, 1, 1, 1, 1, 1};
	cout << soln.maximumSubarraySum(a, 2);
	return 0;
}
