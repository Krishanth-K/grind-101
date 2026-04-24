#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int maximumBeauty(vector<int> &nums, int k)
	{
		int n = nums.size();
		int slow = 0, fast = 0;

		std::unordered_map<int, int> freq;
		int freqNum = nums[0];

		for (fast = 0; fast < n; fast++)
		{
			freq[nums[fast]]++;

			// shrink
			if (fast - slow + 1 > k)
			{
				freq[nums[slow]]--;
				slow++;
			}

			if (freq[nums[fast]] > freq[freqNum])
				freqNum = nums[fast];
		}

		if (k == 1)
			return freq[freqNum];
		return (n > k) ? freq[freqNum] + k : freq[freqNum];
	}
};

int main()
{
	Solution soln;
	return 0;
}
