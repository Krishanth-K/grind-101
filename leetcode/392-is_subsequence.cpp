// diff:

#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	bool isSubsequence(string s, string t)
	{
		int slow = 0, fast = 0;

		for (slow = 0; slow < s.size(); slow++, fast++)
		{
			while (fast < t.size() && s[slow] != t[fast])
				fast++;

			if (fast == t.size())
				return false;
		}

		return true;
	}
};

int main()
{
	Solution soln;
	cout << soln.isSubsequence("aaaaaa", "bbaaaa");
	return 0;
}
