#include <deque>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

static const int speedup = []() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

class Solution {
  public:
	long long continuousSubarrays(vector<int> &nums)
	{
		int n = nums.size();
		int slow = 0, fast = 0;
		long long count = 0;

		std::deque<int> max;
		std::deque<int> min;

		for (fast = 0; fast < n; fast++)
		{
			int current = nums[fast];

			while (max.size() > 0 && nums[fast] > nums[max.back()])
				max.pop_back();
			max.push_back(fast);

			while (min.size() > 0 && nums[fast] < nums[min.back()])
				min.pop_back();
			min.push_back(fast);

			while (nums[max.front()] - nums[min.front()] > 2)
			{
				if (min.front() == slow)
					min.pop_front();

				if (max.front() == slow)
					max.pop_front();

				slow++;
			}

			count += fast - slow + 1;
		}

		return count;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {5, 4, 2, 4};
	cout << soln.continuousSubarrays(a);
	return 0;
}
