#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	vector<int> findAnagrams(string s, string p)
	{
		int n = s.size();
		int slow = 0, fast = 0;

		vector<int> res;

		int uniqueElementNotInWindow = 0;
		int target[26] = {0};
		int count[26] = {0};

		// find freq of char in p
		for (auto &c : p)
		{
			// keep count of unique_chars
			if (target[c - 'a'] == 0)
				uniqueElementNotInWindow++;

			target[c - 'a']++;
		}

		for (fast = 0; fast < n; fast++)
		{
			char current = s[fast];
			count[current - 'a']++;

			// all occurances of one type of char is inside the window
			if (count[current - 'a'] == target[current - 'a'])
				uniqueElementNotInWindow--;

			// shrink if size is larger
			if (fast - slow + 1 > p.size())
			{
				// counts wont be equal after decrementing
				// so all occurances of one type of char is not inside window
				if (count[s[slow] - 'a'] == target[s[slow] - 'a'])
					uniqueElementNotInWindow++;

				count[s[slow] - 'a']--;
				slow++;
			}

			if (uniqueElementNotInWindow == 0)
				res.push_back(slow);
		}

		return res;
	}
};

int main()
{
	Solution soln;
	return 0;
}
