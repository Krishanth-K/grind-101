#include <climits>
#include <deque>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k)
	{
		int n = nums.size();

		int fast = 0, slow = 0;
		int currMax = nums[0];
		vector<int> res;
		res.reserve(n);

		// store indices, instead of actual values
		std::deque<int> max_idx;

		for (fast = 0; fast < n; fast++)
		{
			int current = nums[fast];

			while (max_idx.size() > 0 && current >= nums[max_idx.back()])
				max_idx.pop_back();
			max_idx.push_back(fast);

			// shrink window if larger than k
			if (fast - slow + 1 > k)
			{
				if (slow == max_idx.front())
					max_idx.pop_front();

				slow++;
			}

			if (fast - slow + 1 == k)
				res.push_back(nums[max_idx.front()]);
			// cout << nums[max_idx.front()];
		}

		return res;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
	soln.maxSlidingWindow(a, 3);

	return 0;
}
