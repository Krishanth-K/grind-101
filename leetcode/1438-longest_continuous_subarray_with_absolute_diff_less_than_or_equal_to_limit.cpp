#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <set>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int longestSubarray(vector<int> &nums, int limit)
	{
		static const int speedup = []() {
			std::ios_base::sync_with_stdio(false);
			std::cin.tie(NULL);
			return 0;
		}();

		int n = nums.size();
		int slow = 0, fast = 0;
		int count = 0;

		if (n <= 1)
			return n;

		// monotonic queues are faster
		std::deque<int> min;
		std::deque<int> max;

		for (fast = 0; fast < n; fast++)
		{
			int current = nums[fast];

			// add to the monotonic queues
			while (min.size() > 0 && min.back() > current)
				min.pop_back();
			min.push_back(current);

			while (max.size() > 0 && current > max.back())
				max.pop_back();
			max.push_back(current);

			int low = min.front();
			int high = max.front();

			// shrink condition
			if (high - low > limit)
			{
				if (nums[slow] == min.front())
					min.pop_front();
				if (nums[slow] == max.front())
					max.pop_front();

				slow++;
			}

			// count = std::max(count, fast - slow + 1);
		}

		// // multiset method - slower - log n
		// std::multiset<int> heap;
		// for (fast = 0; fast < n; fast++)
		// {
		// 	// add to the heap
		// 	heap.insert(nums[fast]);
		//
		// 	int low = *heap.begin();
		// 	int high = *heap.rbegin();
		//
		// 	// shrink condition
		// 	if (high - low > limit)
		// 	{
		// 		heap.erase(heap.find(nums[slow]));
		// 		slow++;
		// 	}
		//
		// 	count = std::max(count, fast - slow + 1);
		// }

		return fast - slow;
	}
};

int main()
{
	Solution soln;
	return 0;
}
