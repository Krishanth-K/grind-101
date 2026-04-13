#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  public:
	string removeBackspace(string s)
	{
		int n = s.size();
		int write = 0, read = 0;

		while (read < n)
		{
			if (s[read] == '#')
			{
				if (write > 0)
					write--;
			}

			else
				s[write++] = s[read];

			read++;
		}

		return s.substr(0, write);
	}

	bool backspaceCompare(string s, string t)
	{
		if (removeBackspace(s) == removeBackspace(t))
			return true;

		return false;
	}
};

int main()
{
	Solution soln;
	string s = "a#c";
	string t = "b";

	cout << soln.removeBackspace(s) << std::endl;
	cout << soln.removeBackspace(t) << std::endl;

	return 0;
}
