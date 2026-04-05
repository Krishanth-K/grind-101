// tag
// tag two pointers

// diff: easy

// url: https://leetcode.com/problems/two-sum/

#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		// store rem:index in the map
		std::unordered_map<int, int> map;

		// optimisation: allocate mem upfront to prevent hashmap from rebuilding
		// itself
		map.reserve(nums.size());

		for (int i = 0; i < nums.size(); i++)
		{
			int val = nums[i];
			int rem = target - val;

			if (map.find(rem) != map.end())
				return {i, map[rem]};

			map[val] = i;
		}

		return {};
	}
};

int main()
{
	Solution soln;
	return 0;
}
