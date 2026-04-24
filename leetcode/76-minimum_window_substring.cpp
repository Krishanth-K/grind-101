#include <iostream>
#include <ostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	string minWindow(string s, string t)
	{
		int m = s.size();
		int n = t.size();

		if (m < n)
			return "";

		// string s = "ADOBECODEBANC";
		// string t = "ABC";

		int target[128] = {0};
		int count[128] = {0};
		int uniqueCharsNotInWindow = 0;

		int fast = 0, slow = 0;
		int size = m;
		int start = 0, end = 0;

		// find counts of all char
		for (const auto &c : t)
		{
			target[c - 'A']++;

			if (target[c - 'A'] <= 1)
				uniqueCharsNotInWindow++;
		}

		for (fast = 0; fast < m; fast++)
		{
			count[s[fast] - 'A']++;

			if (count[s[fast] - 'A'] == target[s[fast] - 'A'])
				uniqueCharsNotInWindow--;

			while (slow < fast &&
			       (count[s[slow] - 'A'] > target[s[slow] - 'A']))
			{
				count[s[slow] - 'A']--;
				slow++;
			}

			if (uniqueCharsNotInWindow == 0 && (size >= fast - slow + 1))
			{
				size = fast - slow + 1;
				start = slow;
				end = fast;
			}
		}

		return (uniqueCharsNotInWindow == 0) ? s.substr(start, end - start + 1)
		                                     : "";
	}
};

int main()
{
	Solution soln;
	string s = "aa";
	string t = "aa";
	cout << soln.minWindow(s, t);
	return 0;
}
