#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<int> sortArrayByParity(vector<int> &nums)
	{
		int fast = 1, slow = 0;
		int n = nums.size();

		if (n < 2)
			return nums;

		while (fast < n)
		{
			if (fast == slow)
				fast++;

			if (fast < n && nums[fast] % 2 == 0)
				std::swap(nums[fast], nums[slow++]);
			else
				fast++;
		}
		return nums;
	}
};

int main()
{
	Solution soln;
	return 0;
}
