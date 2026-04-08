// diff: medium

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int findDuplicate(vector<int> &nums)
	{
		// Add this at the very top of your solution or inside the class
		static const int speedup = []() {
			std::ios_base::sync_with_stdio(false);
			std::cin.tie(NULL);
			return 0;
		}();

		int fast = 0, slow = 0;

		do
		{
			fast = nums[nums[fast]];
			slow = nums[slow];
		}
		while (fast != slow);

		int head = 0;
		while (head != slow)
		{
			slow = nums[slow];
			head = nums[head];
		}

		return slow;
	}
};

int main()
{
	Solution soln;
	vector<int> a = {1, 3, 4, 2, 2};

	int b = 0;
	cout << soln.findDuplicate(a);

	return 0;
}
