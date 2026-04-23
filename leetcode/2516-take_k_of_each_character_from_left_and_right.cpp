#include <algorithm>
#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	int takeCharacters(string s, int k)
	{
		int maxSize = -1;
		int slow = 0, fast = 0;
		int n = s.size();

		// calculate maxCount
		int maxCount[3] = {0};
		for (const auto &c : s)
			maxCount[c - 'a']++;

		// early exit
		if (maxCount[0] < k || maxCount[1] < k || maxCount[2] < k)
			return -1;

		// count of 'a', 'b', 'c'
		int count[3] = {0};
		int target[3] = {
		    maxCount[0] - k,
		    maxCount[1] - k,
		    maxCount[2] - k,
		};

		for (fast = 0; fast < n; fast++)
		{
			count[s[fast] - 'a']++;

			// shrink window
			while (count[0] > target[0] || count[1] > target[1] ||
			       count[2] > target[2])
			{
				count[s[slow] - 'a']--;
				slow++;
			}

			maxSize = std::max(maxSize, fast - slow + 1);
		}

		return n - maxSize;
	}
};

int main()
{
	Solution soln;
	return 0;
}
