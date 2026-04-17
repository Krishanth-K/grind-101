#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int numSubarrayProductLessThanK(vector<int> &nums, int k)
	{
		int n = nums.size();
		int slow = 0;
		int fast = 0;
		double prod = 1;
		int count = 0;

		for (int fast = 0; fast < n; fast++)
		{
			// update product
			prod *= nums[fast];

			// if it exceeds k, shrink the window by moving the slow pointer
			while (slow <= fast && prod >= k)
			{
				prod /= nums[slow];
				slow++;
			}

			// update count
			count += fast - slow + 1;
		}

		return count;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {10, 5, 2, 6};
	int res = soln.numSubarrayProductLessThanK(a, 100);

	cout << res;

	return 0;
}
