#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

// anagrams question is the same as this

class Solution {
  public:
	bool checkInclusion(string s1, string s2)
	{
		int n = s2.size();

		int satisfied = 0, uniqueChars = 0;
		int target[26] = {0};
		int count[26] = {0};

		for (auto &c : s1)
		{
			// keep track of uniqueChars
			if (target[c - 'a'] == 0)
				uniqueChars++;

			target[c - 'a']++;
		}

		int slow = 0, fast = 0;
		for (fast = 0; fast < n; fast++)
		{
			int right = s2[fast] - 'a';
			count[right]++;

			if (count[right] == target[right])
				satisfied++;

			if (fast - slow + 1 > s1.size())
			{
				int left = s2[slow] - 'a';
				if (count[left] == target[left])
					satisfied--;

				count[left]--;
				slow++;
			}

			if (satisfied == uniqueChars)
				return true;
		}

		return false;
	}
};

int main()
{
	Solution soln;
	return 0;
}
