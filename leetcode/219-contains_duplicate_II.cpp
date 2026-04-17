#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	bool containsNearbyDuplicate(vector<int> &nums, int k)
	{
		// // set based method
		// std::unordered_set<int> window;
		// window.reserve(nums.size());
		//
		// for (int i = 0; i < nums.size(); i++)
		// {
		// 	// remove the element at k-i, so set only contains the window
		// 	if (i > k)
		// 		window.erase(nums[i - k - 1]);
		//
		// 	if (window.count(nums[i]))
		// 		return true;
		// 	window.insert(nums[i]);
		// }

		// hashmap based method
		std::unordered_map<int, int> lastSeen;
		lastSeen.reserve(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			int current = nums[i];

			// if not seen, add it
			if (lastSeen.find(current) == lastSeen.end())
				lastSeen[current] = i;

			// already not seen
			else
			{
				int j = lastSeen[current];

				if (abs(i - j) <= k)
					return true;
				else
					lastSeen[current] = i;
			}
		}

		return false;
	}
};

int main()
{
	Solution soln;
	return 0;
}
