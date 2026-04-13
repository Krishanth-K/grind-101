#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	double findMaxAverage(vector<int> &nums, int k)
	{
		int n = nums.size();
		int left = 0, right = k - 1;

		// initial value of sum
		double sum = std::accumulate(nums.begin(), nums.begin() + k, 0.0);
		double max_sum = sum;

		// find max sum of a subarray
		while (right < n)
		{
			// update sum
			if (left > 0)
			{
				sum -= nums[left - 1];
				sum += nums[right];
			}

			if (sum > max_sum)
				max_sum = sum;

			right++;
			left++;
		}

		double res = max_sum / k;

		return res;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {1, 12, -5, -6, 50, 3};
	soln.findMaxAverage(a, 4);
	return 0;
}
