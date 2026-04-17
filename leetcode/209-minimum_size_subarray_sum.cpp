#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int minSubArrayLen(int target, vector<int> &nums)
	{
		int n = nums.size();
		int slow = 0;
		int sum = 0;
		int minLength = n + 1;

		for (int fast = 0; fast < n; fast++)
		{
			// 1. Expand the window
			sum += nums[fast];

			// 2. Contract the window as much as possible
			while (sum >= target)
			{
				// 3. Update result
				minLength = std::min(minLength, fast - slow + 1);

				sum -= nums[slow];
				slow++;
			}
		}

		return (minLength > n) ? 0 : minLength;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {1, 4, 4};
	soln.minSubArrayLen(4, a);
	return 0;
}
